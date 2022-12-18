#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QByteArray>
#include <QCloseEvent>
#include <QListWidgetItem>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *);

private slots:
    void on_btnOpenFile_clicked();

    void on_lnkClear_linkActivated(const QString &link);

    void on_btnCalc_clicked();

    void on_btnCompare_clicked();

    void on_btnCopyMd5_clicked();

    void on_btnSaveResult_clicked();

    void on_btnDelCur_clicked();

    void on_btnDelAll_clicked();

    void on_listFiles_currentRowChanged(int currentRow);

    void on_btnCalcAll_clicked();

    void on_progMd5_valueChanged(int value);

    void on_progAll_valueChanged(int value);

private:
    Ui::MainWindow *ui;

protected:
    QByteArray m_md5;
    bool m_bRun;
    bool m_bContinue;
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    QString CalcMd5(const QString &sFile, double curlong);
    QList<quint64> m_sizeList;
    double m_dLong;
};

#endif // MAINWINDOW_H
