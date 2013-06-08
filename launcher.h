#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QDialog>

namespace Ui {
class Launcher;
}

class Launcher : public QDialog
{
    Q_OBJECT
    
public:
    explicit Launcher(QWidget *parent = 0);
    ~Launcher();
private slots:
    void on_okButton_clicked();
    void on_exitButton_clicked();
private:
    Ui::Launcher *_ui;
};

#endif // LAUNCHER_H
