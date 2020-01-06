#ifndef SHELLMANAGER_H
#define SHELLMANAGER_H

#include <QString>
#include <QThread>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include <QProcess>
#include <QDebug>

class shellManager : public QObject
{
    Q_OBJECT
public:
    shellManager();
    ~shellManager();
    void exc(QString cmd);
    QProcess        *shell_processor;

private:

private slots:
    void on_finished(int,QProcess::ExitStatus);
    void on_state_changed(QProcess::ProcessState);
    void on_started();
    void on_error(QProcess::ProcessError);

protected:
    void run();
signals:
    void message(QString);
    void errorstate(bool);
};

#endif // SHELLMANAGER_H
