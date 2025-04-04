/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *startButton;
    QPushButton *pushButton;
    QPushButton *popButton;
    QPushButton *closeButton;
    QGraphicsView *graphicsView;
    QLineEdit *numberLineEdit;
    QLineEdit *baseLineEdit;
    QLineEdit *resultLineEdit;
    QPushButton *convertButton;
    QLabel *bracketMatchingLabel;
    QLabel *baseConversionLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *clearConversionButton;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1544, 627);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 100, 1441, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 20pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(176, 176, 176);"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(10, 40, 61, 41));
        startButton->setStyleSheet(QString::fromUtf8("border-bottom-color: rgb(166, 166, 166);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 40, 61, 41));
        popButton = new QPushButton(centralwidget);
        popButton->setObjectName("popButton");
        popButton->setGeometry(QRect(260, 40, 71, 41));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(390, 40, 61, 41));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 160, 1531, 251));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"background-color: rgb(0, 255, 255);"));
        numberLineEdit = new QLineEdit(centralwidget);
        numberLineEdit->setObjectName("numberLineEdit");
        numberLineEdit->setGeometry(QRect(0, 490, 221, 41));
        numberLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);\n"
"font: 20pt \"Microsoft YaHei UI\";"));
        baseLineEdit = new QLineEdit(centralwidget);
        baseLineEdit->setObjectName("baseLineEdit");
        baseLineEdit->setGeometry(QRect(350, 490, 81, 41));
        baseLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);\n"
"font: 20pt \"Microsoft YaHei UI\";"));
        resultLineEdit = new QLineEdit(centralwidget);
        resultLineEdit->setObjectName("resultLineEdit");
        resultLineEdit->setGeometry(QRect(660, 490, 631, 41));
        resultLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(180, 180, 180);\n"
"font: 20pt \"Microsoft YaHei UI\";"));
        convertButton = new QPushButton(centralwidget);
        convertButton->setObjectName("convertButton");
        convertButton->setGeometry(QRect(540, 440, 71, 41));
        bracketMatchingLabel = new QLabel(centralwidget);
        bracketMatchingLabel->setObjectName("bracketMatchingLabel");
        bracketMatchingLabel->setGeometry(QRect(10, 0, 181, 41));
        baseConversionLabel = new QLabel(centralwidget);
        baseConversionLabel->setObjectName("baseConversionLabel");
        baseConversionLabel->setGeometry(QRect(10, 420, 201, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 460, 171, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(350, 460, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(660, 460, 131, 31));
        clearConversionButton = new QPushButton(centralwidget);
        clearConversionButton->setObjectName("clearConversionButton");
        clearConversionButton->setGeometry(QRect(540, 530, 61, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 100, 101, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 130, 51, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1544, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        popButton->setText(QCoreApplication::translate("MainWindow", "Pop", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        bracketMatchingLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; text-decoration: underline; color:#fc0230;\">\345\237\272\344\272\216\346\240\210\347\232\204\346\213\254\345\217\267\345\214\271\351\205\215\357\274\232</span></p></body></html>", nullptr));
        baseConversionLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; text-decoration: underline; color:#fc0230;\">\345\237\272\344\272\216\346\240\210\345\256\236\347\216\260\350\277\233\345\210\266\350\275\254\346\215\242\357\274\232</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; font-style:italic;\">\345\216\237\345\247\213\345\215\201\350\277\233\345\210\266\346\225\260\345\255\227\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; font-style:italic;\">\350\277\233\345\210\266\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; font-style:italic;\">\350\275\254\346\215\242\345\220\216\346\225\260\345\255\227</span><span style=\" font-size:16pt; font-weight:700; font-style:italic;\">\357\274\232</span></p></body></html>", nullptr));
        clearConversionButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; font-style:italic;\">\345\276\205\346\243\200\346\265\213\345\255\227\347\254\246\357\274\232</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; font-style:italic;\">\345\212\250\347\224\273\357\274\232</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
