#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    smp(new shellManager),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("adb tools");
    initQssStyleSheet();
    connect(smp,SIGNAL(message(QString)),this,SLOT(on_message(QString)));
    connect(smp,SIGNAL(errorstate(bool)),this,SLOT(on_error_state(bool)));
    qDebug() << "run ...";
    //smp->start();
    ui->textBrowserInfo->append("console...");
//  smp->shell_processor->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_message(QString str)
{
    ui->textBrowserInfo->append(str);
}
void MainWindow::on_error_state(bool state)
{
    if (state == false) {
        ui->textBrowserInfo->append("error command content.");
    }
}
void MainWindow::initQssStyleSheet()
{
    QString     qss;
    QFile       qssFile(":/qss/Dark-Y.qss");
    qssFile.open(QFile::ReadOnly);
    if( qssFile.isOpen() ) {
        qss     = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
}

void MainWindow::on_pushButtonCmd_clicked()
{
    bool ret;
    ret = copyDirectoryFiles(QDir::currentPath()+"/adb","C:/Windows/SysWOW64",true);
    qDebug() << QDir::currentPath()+"/adb";
    ui->textBrowserInfo->append("copy adb files from " + QDir::currentPath()+"/adb" + " to C:/Windows/SysWOW64" );

    popInfoWindow("Write adb files succussful!");

}

//拷贝文件：
bool MainWindow::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile     = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }
    return true;
}
//拷贝文件夹：
bool MainWindow::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            /// 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}
void MainWindow::on_pushButtonEnter_clicked()
{
    QString cmd;
    cmd = ui->lineEditCmd->text();
    adb_command(cmd);
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->textBrowserInfo->clear();
}
void MainWindow::popErrorWindow(QString info)
{
    QMessageBox *errorBox;

    errorBox = new QMessageBox();
    errorBox->setModal(true);
    errorBox->setText(info);
    errorBox->setWindowTitle("Error");
    errorBox->setIcon(QMessageBox::Critical);
    //errorBox->critical(this, ERROR_TITLE_ERROR_TITLE, info);
    errorBox->show();
}

void MainWindow::popInfoWindow(QString info)
{
    QMessageBox *infoBox;
    infoBox = new QMessageBox();
    infoBox->setModal(true);
    infoBox->setText(info);
    infoBox->setWindowTitle("Information");
    infoBox->setIcon(QMessageBox::Information);
    //infoBox->information(this, ERROR_TITLE_NO_ERROR, info);
    infoBox->show();
}

void MainWindow::on_pushButtonOneKey_clicked()
{
    // example
    // 注意： 路径反斜杠 用/ 如C:\Windows\SysWOW64 要替换为C:/Windows/SysWOW64
    adb_command("adb devices");
    adb_command("adb version");
    adb_command("adb version");
    adb_command("adb version");
    adb_command("adb devices");
    // ....

    // 你的命令顺序
    // ....

}

void MainWindow::adb_command(QString cmd)
{
    QCoreApplication::processEvents();
    smp->exc(cmd);
    ui->textBrowserInfo->append("do cmd... wait...");
    smp->shell_processor->waitForFinished(-1);

}
