/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCmd;
    QLabel *label_2;
    QLineEdit *lineEditCmd;
    QPushButton *pushButtonEnter;
    QPushButton *pushButtonClear;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonOne;
    QPushButton *pushButtonTwo;
    QPushButton *pushButtonOneKey;
    QLabel *label;
    QTextBrowser *textBrowserInfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(625, 482);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonCmd = new QPushButton(centralWidget);
        pushButtonCmd->setObjectName(QStringLiteral("pushButtonCmd"));
        pushButtonCmd->setMinimumSize(QSize(28, 28));
        pushButtonCmd->setMaximumSize(QSize(28, 28));
        pushButtonCmd->setStyleSheet(QStringLiteral("background-image: url(:/img/ima2.png);"));

        horizontalLayout->addWidget(pushButtonCmd);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditCmd = new QLineEdit(centralWidget);
        lineEditCmd->setObjectName(QStringLiteral("lineEditCmd"));

        horizontalLayout->addWidget(lineEditCmd);

        pushButtonEnter = new QPushButton(centralWidget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));

        horizontalLayout->addWidget(pushButtonEnter);

        pushButtonClear = new QPushButton(centralWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));

        horizontalLayout->addWidget(pushButtonClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonOne = new QPushButton(centralWidget);
        pushButtonOne->setObjectName(QStringLiteral("pushButtonOne"));

        horizontalLayout_2->addWidget(pushButtonOne);

        pushButtonTwo = new QPushButton(centralWidget);
        pushButtonTwo->setObjectName(QStringLiteral("pushButtonTwo"));

        horizontalLayout_2->addWidget(pushButtonTwo);

        pushButtonOneKey = new QPushButton(centralWidget);
        pushButtonOneKey->setObjectName(QStringLiteral("pushButtonOneKey"));

        horizontalLayout_2->addWidget(pushButtonOneKey);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        textBrowserInfo = new QTextBrowser(centralWidget);
        textBrowserInfo->setObjectName(QStringLiteral("textBrowserInfo"));

        verticalLayout->addWidget(textBrowserInfo);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 625, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
#ifndef QT_NO_STATUSTIP
        pushButtonCmd->setStatusTip(QApplication::translate("MainWindow", "\345\206\231\345\205\245abd\346\226\207\344\273\266\345\210\260C\347\233\230", nullptr));
#endif // QT_NO_STATUSTIP
        pushButtonCmd->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "cmd:>", nullptr));
        pushButtonEnter->setText(QApplication::translate("MainWindow", "Enter", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButtonEnter->setShortcut(QApplication::translate("MainWindow", "Enter", nullptr));
#endif // QT_NO_SHORTCUT
        pushButtonClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButtonOne->setText(QApplication::translate("MainWindow", "Button1", nullptr));
        pushButtonTwo->setText(QApplication::translate("MainWindow", "Button2", nullptr));
        pushButtonOneKey->setText(QApplication::translate("MainWindow", "oneKey", nullptr));
        label->setText(QApplication::translate("MainWindow", "Information:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
