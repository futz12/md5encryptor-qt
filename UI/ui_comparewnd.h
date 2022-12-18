/********************************************************************************
** Form generated from reading UI file 'comparewnd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREWND_H
#define UI_COMPAREWND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompareWnd
{
public:
    QLabel *label;
    QLineEdit *edtCurMd5;
    QLabel *label_2;
    QLineEdit *edtOtherMd5;
    QLabel *label_3;
    QLabel *stcResult;
    QPushButton *btnClose;

    void setupUi(QWidget *CompareWnd)
    {
        if (CompareWnd->objectName().isEmpty())
            CompareWnd->setObjectName(QString::fromUtf8("CompareWnd"));
        CompareWnd->resize(441, 162);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        CompareWnd->setFont(font);
        label = new QLabel(CompareWnd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 31));
        edtCurMd5 = new QLineEdit(CompareWnd);
        edtCurMd5->setObjectName(QString::fromUtf8("edtCurMd5"));
        edtCurMd5->setGeometry(QRect(150, 10, 281, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        edtCurMd5->setFont(font1);
        label_2 = new QLabel(CompareWnd);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 141, 31));
        edtOtherMd5 = new QLineEdit(CompareWnd);
        edtOtherMd5->setObjectName(QString::fromUtf8("edtOtherMd5"));
        edtOtherMd5->setGeometry(QRect(150, 50, 281, 31));
        edtOtherMd5->setFont(font1);
        label_3 = new QLabel(CompareWnd);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 141, 31));
        stcResult = new QLabel(CompareWnd);
        stcResult->setObjectName(QString::fromUtf8("stcResult"));
        stcResult->setGeometry(QRect(150, 90, 281, 31));
        btnClose = new QPushButton(CompareWnd);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(302, 120, 131, 31));

        retranslateUi(CompareWnd);

        QMetaObject::connectSlotsByName(CompareWnd);
    } // setupUi

    void retranslateUi(QWidget *CompareWnd)
    {
        CompareWnd->setWindowTitle(QApplication::translate("CompareWnd", "MD5\346\240\241\351\252\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CompareWnd", "\345\275\223\345\211\215MD5\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CompareWnd", "\350\246\201\344\270\216\345\205\266\346\257\224\345\257\271\347\232\204MD5\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CompareWnd", "\346\240\241\351\252\214\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        stcResult->setText(QApplication::translate("CompareWnd", "<p style=\"color:#ff0000;\">\344\270\215\347\233\270\345\220\214</p>", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("CompareWnd", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CompareWnd: public Ui_CompareWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREWND_H
