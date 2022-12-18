#ifndef COMPAREWND_H
#define COMPAREWND_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class CompareWnd;
}

class CompareWnd : public QDialog
{
    Q_OBJECT

public:
    explicit CompareWnd(QWidget *parent, const QString &md5);
    ~CompareWnd();

private slots:
    void on_edtCurMd5_textChanged(const QString &arg1);

    void on_edtOtherMd5_textChanged(const QString &arg1);

    void on_btnClose_clicked();

private:
    Ui::CompareWnd *ui;
};

#endif // COMPAREWND_H
