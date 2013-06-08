#include "launcher.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString lang = QLocale::system().name();
    lang.replace('_', '-');
    QString fileName = qApp->applicationDirPath();
    fileName.append("/launcher_");
    fileName.append(lang);
    QTranslator ts;
    if (ts.load(fileName))
        qApp->installTranslator(&ts);

    Launcher w;
    w.show();
    
    return a.exec();
}
