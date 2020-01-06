#include "shellmanager.h"

shellManager::shellManager():
    shell_processor(new QProcess)
{
    connect(shell_processor,SIGNAL(started()),this,SLOT(on_started()));
    connect(shell_processor,SIGNAL(error(QProcess::ProcessError)),this, SLOT(on_error(QProcess::ProcessError)));
    connect(shell_processor,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(on_finished(int,QProcess::ExitStatus)));
    connect(shell_processor,SIGNAL(stateChanged(QProcess::ProcessState)),this,SLOT(on_state_changed(QProcess::ProcessState)));

}
shellManager::~shellManager()
{

}
void shellManager::exc(QString cmd)
{
    //cmd.append("\r\n");
    shell_processor->start(cmd);
    //shell_processor->waitForFinished(1000);
}

void shellManager::on_started()
{
    qDebug() << "process on start;";

}
void shellManager::on_error(QProcess::ProcessError error) {
     emit message("encounter_error!");
}
void shellManager::on_finished(int exitCode,QProcess::ExitStatus exitStatus)
{
    QString out_str;
    qDebug()<<"finished";
    qDebug()<<exitCode;// 被调用程序的main返回的int
    qDebug()<<exitStatus;// QProcess::ExitStatus(NormalExit)
    qDebug() <<"finished-output-readAll:";
    //out_str = QString::fromLocal8Bit(shell_processor->readAll());

    //qDebug()<< out_str;
    qDebug()<<"finished-output-readAllStandardOutput:";
    qDebug()<<QString::fromLocal8Bit(shell_processor->readAllStandardOutput());
    emit message(out_str);
    if (out_str.contains("Initialize provisioning tool failed!")) {

    }
}


void shellManager::on_state_changed(QProcess::ProcessState state)
{
    qDebug()<<"show state:";
    switch(state)
    {
     case QProcess::NotRunning:
        qDebug()<<"Not Running";
        //emit errorstate(false);
        break;
    case QProcess::Starting:
        qDebug()<<"Starting";
        emit message("starting....");
        break;
    case QProcess::Running:
        qDebug()<<"Running";
        emit message("runing....");
        break;
    default:
        qDebug()<<"otherState";
        break;
    }
}
void shellManager::run()
{
//    qDebug() << " start ....run ....";
//    shell_processor->start("ipconfig\r\n");
}


