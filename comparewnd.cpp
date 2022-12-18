#include "comparewnd.h"
#include "ui_comparewnd.h"

CompareWnd::CompareWnd(QWidget *parent, const QString &md5) :
    QDialog(parent),
    ui(new Ui::CompareWnd)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() &~ Qt::WindowContextHelpButtonHint);
    ui->edtCurMd5->setText(md5);

    if (md5 != "")
        ui->edtOtherMd5->setFocus();
    else
    {
        ui->edtCurMd5->setFocus();
        ui->stcResult->setText("<p style=\"color:#00ff00\">相同</p>");
    }
}

CompareWnd::~CompareWnd()
{
    delete ui;
}

void CompareWnd::on_edtCurMd5_textChanged(const QString &arg1)
{
    if (ui->edtCurMd5->text().compare(ui->edtOtherMd5->text(), Qt::CaseInsensitive) == 0)
        ui->stcResult->setText("<p style=\"color:#00ff00\">相同</p>");
    else
        ui->stcResult->setText("<p style=\"color:#ff0000\">不相同</p>");
}

void CompareWnd::on_edtOtherMd5_textChanged(const QString &arg1)
{
    on_edtCurMd5_textChanged(arg1);
}

void CompareWnd::on_btnClose_clicked()
{
    close();
}
