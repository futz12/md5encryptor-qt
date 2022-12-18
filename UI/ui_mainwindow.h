/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *btnOpenFile;
    QLabel *lnkClear;
    QTextEdit *edtMd5;
    QPushButton *btnCalc;
    QPushButton *btnCompare;
    QLabel *stcAbout;
    QLabel *label;
    QProgressBar *progMd5;
    QPushButton *btnSaveResult;
    QPushButton *btnCopyMd5;
    QFrame *line;
    QListWidget *listFiles;
    QPushButton *btnDelCur;
    QPushButton *btnDelAll;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QProgressBar *progAll;
    QLabel *label_5;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(803, 492);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setAcceptDrops(true);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"color:rgb(250, 250, 250);\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QPushButton{\n"
"color:rgb(250, 250, 250);\n"
"border:1px solid rgb(128, 128, 128);\n"
"background-color: rgb(40 ,40 ,40);\n"
"width: 60px;\n"
"height: 30px;\n"
"border-radius:5px;\n"
"}\n"
"QPushButton:hover{\n"
"border-color:rgb(255, 170, 0);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(255, 170, 0);\n"
"border-color: rgb(128, 128, 128);\n"
"color:black;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: rgb(60, 60, 60);\n"
"color: rgb(160, 160, 160);\n"
"}\n"
"QTextEdit{\n"
"background-color: rgb(40 ,40 ,40);\n"
"border:1px solid rgb(128, 128, 128);\n"
"border-radius:5px;\n"
"}\n"
"QLineEdit{\n"
"background-color: rgb(40, 40, 40);\n"
"border:1px solid rgb(128, 128, 128);\n"
"border-radius:5px;\n"
"}\n"
"#MainWindow{\n"
"background-color: rgb(80, 80, 80);\n"
"}\n"
"#CompareWnd{\n"
"background-color: rgb(80, 80, 80);\n"
"}\n"
"#stcResult{\n"
"color:rgb(250, 250, 250);\n"
"font: 9pt \"\345"
                        "\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font-weight: bold;\n"
"}\n"
"QDialog{\n"
"background-color: rgb(80, 80, 80);\n"
"}\n"
"QListWidget{\n"
"background-color: rgb(40, 40, 40);\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"	font:9pt;\n"
"	border-radius:5px;\n"
"	text-align:center;\n"
"	border:1px solid #808080;\n"
"	background-color: rgb(40, 40, 40);\n"
"}\n"
"QProgressBar:chunk{\n"
"	border-radius:5px;\n"
"	background-color:rgb(255, 170, 0);\n"
"}"));
        btnOpenFile = new QPushButton(MainWindow);
        btnOpenFile->setObjectName(QString::fromUtf8("btnOpenFile"));
        btnOpenFile->setGeometry(QRect(200, 10, 111, 31));
        btnOpenFile->setFlat(false);
        lnkClear = new QLabel(MainWindow);
        lnkClear->setObjectName(QString::fromUtf8("lnkClear"));
        lnkClear->setGeometry(QRect(320, 10, 171, 31));
        lnkClear->setTextFormat(Qt::AutoText);
        edtMd5 = new QTextEdit(MainWindow);
        edtMd5->setObjectName(QString::fromUtf8("edtMd5"));
        edtMd5->setGeometry(QRect(320, 40, 471, 261));
        edtMd5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        edtMd5->setLineWrapMode(QTextEdit::NoWrap);
        edtMd5->setReadOnly(true);
        edtMd5->setTextInteractionFlags(Qt::TextSelectableByMouse);
        btnCalc = new QPushButton(MainWindow);
        btnCalc->setObjectName(QString::fromUtf8("btnCalc"));
        btnCalc->setGeometry(QRect(320, 310, 151, 41));
        btnCalc->setDefault(true);
        btnCompare = new QPushButton(MainWindow);
        btnCompare->setObjectName(QString::fromUtf8("btnCompare"));
        btnCompare->setGeometry(QRect(320, 410, 151, 41));
        btnCompare->setDefault(false);
        stcAbout = new QLabel(MainWindow);
        stcAbout->setObjectName(QString::fromUtf8("stcAbout"));
        stcAbout->setEnabled(true);
        stcAbout->setGeometry(QRect(20, 460, 781, 31));
        stcAbout->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(480, 310, 71, 41));
        progMd5 = new QProgressBar(MainWindow);
        progMd5->setObjectName(QString::fromUtf8("progMd5"));
        progMd5->setGeometry(QRect(560, 310, 231, 41));
        progMd5->setValue(0);
        btnSaveResult = new QPushButton(MainWindow);
        btnSaveResult->setObjectName(QString::fromUtf8("btnSaveResult"));
        btnSaveResult->setGeometry(QRect(640, 410, 151, 41));
        btnSaveResult->setDefault(false);
        btnCopyMd5 = new QPushButton(MainWindow);
        btnCopyMd5->setObjectName(QString::fromUtf8("btnCopyMd5"));
        btnCopyMd5->setEnabled(true);
        btnCopyMd5->setGeometry(QRect(480, 410, 151, 41));
        btnCopyMd5->setDefault(false);
        line = new QFrame(MainWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 450, 931, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        listFiles = new QListWidget(MainWindow);
        listFiles->setObjectName(QString::fromUtf8("listFiles"));
        listFiles->setGeometry(QRect(10, 50, 301, 321));
        listFiles->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listFiles->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listFiles->setDragEnabled(true);
        listFiles->setDragDropMode(QAbstractItemView::DragDrop);
        listFiles->setDefaultDropAction(Qt::MoveAction);
        btnDelCur = new QPushButton(MainWindow);
        btnDelCur->setObjectName(QString::fromUtf8("btnDelCur"));
        btnDelCur->setEnabled(false);
        btnDelCur->setGeometry(QRect(10, 410, 161, 41));
        btnDelAll = new QPushButton(MainWindow);
        btnDelAll->setObjectName(QString::fromUtf8("btnDelAll"));
        btnDelAll->setGeometry(QRect(180, 410, 131, 41));
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 151, 31));
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 380, 131, 21));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 360, 151, 41));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 360, 72, 41));
        progAll = new QProgressBar(MainWindow);
        progAll->setObjectName(QString::fromUtf8("progAll"));
        progAll->setGeometry(QRect(560, 360, 231, 41));
        progAll->setValue(0);
        label_5 = new QLabel(MainWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 380, 161, 21));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MD5\345\277\253\351\200\237\350\256\241\347\256\227\345\231\250", 0, QApplication::UnicodeUTF8));
        btnOpenFile->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266...", 0, QApplication::UnicodeUTF8));
        lnkClear->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\350\256\241\347\256\227\347\273\223\346\236\234\357\274\232\357\274\210<a href=\"javascript:void(0)\"><span style=\" text-decoration: underline; color:#ffaa00;\">\347\202\271\346\255\244\346\270\205\347\251\272</span></a>\357\274\211</p></body></html>", 0, QApplication::UnicodeUTF8));
        btnCalc->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\275\223\345\211\215\346\226\207\344\273\266MD5", 0, QApplication::UnicodeUTF8));
        btnCompare->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214MD5...", 0, QApplication::UnicodeUTF8));
        stcAbout->setText(QApplication::translate("MainWindow", "MD5\345\277\253\351\200\237\350\256\241\347\256\227\345\231\250 v1.3 by szx0427\357\274\210\345\237\272\344\272\216 Qt 4.8.7\357\274\211", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\233\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        btnSaveResult->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\273\223\346\236\234...", 0, QApplication::UnicodeUTF8));
        btnCopyMd5->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266\345\275\223\345\211\215MD5", 0, QApplication::UnicodeUTF8));
        btnDelCur->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\200\211\346\213\251\347\232\204\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        btnDelAll->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\205\250\351\203\250\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\350\246\201\350\256\241\347\256\227\347\232\204\346\226\207\344\273\266\345\210\227\350\241\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\345\267\262\346\267\273\345\212\240 0 \344\270\252\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\205\250\351\203\250\346\226\207\344\273\266MD5", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\346\200\273\344\275\223\350\277\233\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\345\217\257\346\213\226\346\213\275\346\233\264\346\224\271\351\241\271\347\233\256\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
