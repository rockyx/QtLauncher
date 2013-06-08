#include "launcher.h"
#include "ui_launcher.h"
#include <QProcess>
#include <QDir>
#include <Windows.h>

Launcher::Launcher(QWidget *parent)
    : QDialog(parent)
    , _ui(new Ui::Launcher)
{
    _ui->setupUi(this);
}

Launcher::~Launcher()
{
    delete _ui;
}

void Launcher::on_okButton_clicked()
{
    QDir path(qApp->applicationDirPath());
    QString filePath;
    QStringList env = QProcess::systemEnvironment();

    if (_ui->c168iiradio->isChecked()) {
        path.cd("C168 II");
        filePath = path.absoluteFilePath("Scanner.exe");
    } else {
        path.cd("C168");
        filePath = path.absoluteFilePath("FDT.exe");
    }

    for (QStringList::Iterator i = env.begin(); i != env.end(); ++i) {
        if (i->startsWith("Path=", Qt::CaseInsensitive)) {
            i->append(";");
            i->append(qApp->applicationDirPath());
            i->append(";");
            i->append(path.absolutePath());
            break;
        }
    }

    if (QProcess::startDetached(filePath, env, path.absolutePath())) {
        Sleep(500);
        QString name = tr("CAR-BRAINAutomobile Diagnostic System");
        HWND hWnd = ::FindWindowA(NULL, name.toLocal8Bit().data());

        if (hWnd != NULL) {
            SendMessageA(hWnd, WM_SYSCOMMAND, SC_RESTORE, -1);
        }
        qApp->quit();
    }
}

void Launcher::on_exitButton_clicked()
{
    qApp->quit();
}
