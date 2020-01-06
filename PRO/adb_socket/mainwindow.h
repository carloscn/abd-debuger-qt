#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include "shellmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void                    initQssStyleSheet();

    bool                    copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);
    bool                    copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
private slots:
    void on_pushButtonCmd_clicked();
    void on_message(QString);
    void on_error_state(bool);

    void on_pushButtonEnter_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonOneKey_clicked();

private:
    Ui::MainWindow *ui;
    shellManager *smp;
    void    popErrorWindow      (QString info);
    void    popInfoWindow       (QString info);
    void    adb_command( QString cmd );
};

#endif // MAINWINDOW_H
