#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comparewnd.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QClipboard>
#include <QDebug>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_bRun(true),
    m_bContinue(true),
    m_dLong(0.0)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpenFile_clicked()
{
    QStringList sFiles = QFileDialog::getOpenFileNames(this, "打开文件", "", "All files (*.*)");
    if (sFiles.size() > 0)
    {
        ui->progMd5->setValue(0);
        ui->progAll->setValue(0);
        QListIterator<QString> it(sFiles);
        while (it.hasNext())
            ui->listFiles->addItem(it.next());
        ui->listFiles->setCurrentRow(ui->listFiles->count() - 1);
        ui->stcCount->setText(QString("已添加 %1 个文件").arg(ui->listFiles->count()));
    }
}

void MainWindow::on_lnkClear_linkActivated(const QString &link)
{
    ui->progMd5->setValue(0);
    ui->progAll->setValue(0);
    ui->edtMd5->setText("");
    m_md5.clear();
}

void MainWindow::on_btnCalc_clicked()
{
    if (ui->btnCalc->text() == "停止计算" || ui->btnCalc->text() == "跳过当前")
    {
        int ret =
                QMessageBox::question(this, "询问", "是否停止或跳过当前文件的计算？", QMessageBox::Yes, QMessageBox::No);
        if (ret == QMessageBox::Yes)
            m_bRun = false;
        return;
    }
    if (ui->listFiles->currentRow() == -1)
        QMessageBox::critical(this, "错误", "当前未选择任何文件。", QMessageBox::Ok);
    else
    {
        m_sizeList.clear();
        QFile file(ui->listFiles->currentItem()->text());
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, "错误", "无法打开文件。请检查权限。", QMessageBox::Ok);
            return;
        }
        m_sizeList.push_back(file.size());
        m_dLong = (100.0 * 1024.0 * 100.0) / file.size();
        ui->progAll->setValue(0);

        ui->listFiles->setEnabled(false);
        ui->btnDelCur->setEnabled(false);
        ui->btnDelAll->setEnabled(false);
        ui->btnCalc->setText("停止计算");
        ui->btnCalcAll->setEnabled(false);
        bool bPrefix = false;
        if (ui->edtMd5->toPlainText().size() > 0)
             bPrefix = true;
        QString str = CalcMd5(ui->listFiles->currentItem()->text(), 0);
        ui->progAll->setValue(100);
        if (bPrefix)
            ui->edtMd5->append("===================================");
        ui->edtMd5->append(str);
        ui->btnCalc->setText("计算当前文件MD5");
        ui->btnCalcAll->setEnabled(true);
        ui->listFiles->setEnabled(true);
        ui->btnDelCur->setEnabled(true);
        ui->btnDelAll->setEnabled(true);
    }
}

void MainWindow::on_btnCompare_clicked()
{
    CompareWnd wnd(this, m_md5);
    wnd.exec();
}

void MainWindow::on_btnCopyMd5_clicked()
{
    if (m_md5.size() != 0)
    {
        QClipboard *pBoard = QApplication::clipboard();
        pBoard->setText(m_md5);
    }
    else
        QMessageBox::critical(this, "错误", "当前MD5为空。", QMessageBox::Ok);
}

void MainWindow::on_btnSaveResult_clicked()
{
    QString str = ui->edtMd5->toPlainText();
    if (str.size() == 0)
    {
        QMessageBox::critical(this, "错误", "当前MD5计算结果为空。", QMessageBox::Ok);
        return;
    }
    QString sFile = QFileDialog::getSaveFileName(this, "保存文件", ".", "Text files (*.txt);;All files (*.*)");
    if (sFile.length() == 0)
        return;
    QFile file(sFile);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "错误", "无法创建或打开文件。", QMessageBox::Ok);
        return;
    }
    file.write(str.toAscii());
    file.close();
    QMessageBox::information(this, "成功", "保存文件成功。", QMessageBox::Ok);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    if (ui->btnCalc->text() == "停止计算" || ui->btnCalc->text() == "跳过当前")
    {
        m_bRun = false;
        m_bContinue = false;
        _sleep(100);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    QListIterator<QUrl> it(urls);
    while (it.hasNext())
        ui->listFiles->addItem(it.next().toLocalFile().replace('/', '\\'));
    ui->listFiles->setCurrentRow(ui->listFiles->count() - 1);
    ui->stcCount->setText(QString("已添加 %1 个文件").arg(ui->listFiles->count()));
    ui->progMd5->setValue(0);
    ui->progAll->setValue(0);
}

void MainWindow::on_btnDelCur_clicked()
{
    QListWidgetItem *item = ui->listFiles->currentItem();
    ui->listFiles->removeItemWidget(item);
    delete item;
    ui->stcCount->setText(QString("已添加 %1 个文件").arg(ui->listFiles->count()));
    ui->progMd5->setValue(0);
    ui->progAll->setValue(0);
}

void MainWindow::on_btnDelAll_clicked()
{
    ui->progMd5->setValue(0);
    ui->progAll->setValue(0);
    ui->listFiles->clear();
    ui->stcCount->setText(QString("已添加 0 个文件"));
}

void MainWindow::on_listFiles_currentRowChanged(int currentRow)
{
    if (currentRow == -1)
        ui->btnDelCur->setEnabled(false);
    else
        ui->btnDelCur->setEnabled(true);
}

void MainWindow::on_btnCalcAll_clicked()
{
    if (ui->btnCalcAll->text() == "全部停止")
    {
        int ret =
                QMessageBox::question(this, "询问", "是否要停止全部文件的计算？", QMessageBox::Yes, QMessageBox::No);
        if (ret == QMessageBox::Yes)
        {
            m_bRun = false;
            m_bContinue = false;
        }
        return;
    }

    int c = ui->listFiles->count();
    if (c == 0)
        QMessageBox::critical(this, "错误", "当前未添加任何文件。", QMessageBox::Ok);
    else
    {
        ui->progAll->setValue(0);
        setAcceptDrops(false);
        ui->listFiles->setEnabled(false);
        ui->btnDelCur->setEnabled(false);
        ui->btnDelAll->setEnabled(false);
        ui->btnOpenFile->setEnabled(false);
        ui->btnCalc->setText("跳过当前");
        ui->btnCalcAll->setText("全部停止");
        m_sizeList.clear();
        int i;
        QStringList strlist;
        quint64 total = 0;
        for ( i=0; i<c && m_bContinue; i++ )
        {
            QApplication::processEvents();
            strlist.push_back(ui->listFiles->item(i)->text());
            QFile file(strlist[i].replace('\\', '/'));
            if (!file.open(QIODevice::ReadOnly))
            {
                m_sizeList.push_back(0);
                continue;
            }
            m_sizeList.push_back(file.size());
            total += m_sizeList[i];
        }
        m_dLong = (100.0 * 1024.0 * 100.0) / total;
        for ( i=0; i<c && m_bContinue; i++ )
        {
            ui->listFiles->setCurrentRow(i);
            QApplication::processEvents();
            bool bPrefix = false;
            if (ui->edtMd5->toPlainText().size() > 0)
                 bPrefix = true;
            strlist[i] = CalcMd5(strlist[i], (100.0 * m_sizeList[i]) / total);
            if (bPrefix)
                ui->edtMd5->append("===================================");
            ui->edtMd5->append(strlist[i]);
        }
        ui->progAll->setValue(100);
        if (!m_bContinue)
        {
            ui->edtMd5->append("<span style=\"color:red;\">所有文件计算均已停止。</span>");
            ui->progAll->setValue(0);
            m_bContinue = true;
        }
        setAcceptDrops(true);
        ui->listFiles->setEnabled(true);
        ui->btnDelCur->setEnabled(true);
        ui->btnDelAll->setEnabled(true);
        ui->btnOpenFile->setEnabled(true);
        ui->btnCalc->setText("计算当前文件MD5");
        ui->btnCalcAll->setText("计算全部文件MD5");
    }
}

QString MainWindow::CalcMd5(const QString &sFile, double curlong)
{
    QFile file(sFile);
    QString s = sFile;
    s.replace('/', '\\');
    double original = ui->progAll->value();
    if (!file.exists())
    {
        ui->progMd5->setValue(0);
        ui->progAll->setValue(original + curlong);
        return "<span style=\"color: red;\">错误：" + sFile + "不存在。\n</span>";
    }

    file.open(QIODevice::ReadOnly);
    quint64 sizFile = file.size();
    static QString str;
    str = QString("文件：%1\n大小：%2 字节 (%3 KB, %4 MB)\nMD5：")
            .arg(s)
            .arg(sizFile)
            .arg(QString::number(sizFile / 1024.0, 'f', 2))
            .arg(QString::number(sizFile / 1048576.0, 'f', 2));

    QCryptographicHash h(QCryptographicHash::Md5);
    char szBuf[100 * 1024];
    int nRead = 0;
    quint64 nTotal = 0;
    double l = (100.0 * 1024.0 * 100.0) / sizFile;
    double value = 0;
    double valAll = ui->progAll->value();
    while ((nRead = file.read(szBuf, 100 * 1024)) > 0 && m_bRun)
    {
        QApplication::processEvents();
        nTotal += nRead;
        h.addData(szBuf, nRead);
        ui->progMd5->setValue(value += l);
        ui->progAll->setValue(valAll += m_dLong);
    }

    ui->progAll->setValue(original + curlong);

    if (!m_bRun)
    {
        m_bRun = true;
        ui->progMd5->setValue(0);
        return "<span style=\"color: red;\">文件：" + s + ": 用户中止计算操作。\n</span>";
    }

    if (nTotal != sizFile)
    {
        ui->progMd5->setValue(0);
        return "<span style=\"color: red;\">错误：读取文件" + s + "时出现问题。请检查权限。\n</span>";
    }
    m_md5 = h.result().toHex();
    str += m_md5;

    ui->progMd5->setValue(100);
    return str;
}

void MainWindow::on_progMd5_valueChanged(int value)
{
    if (value > 50)
        ui->progMd5->setStyleSheet("color: black");
    else
        ui->progMd5->setStyleSheet("");
}

void MainWindow::on_progAll_valueChanged(int value)
{
    if (value > 50)
        ui->progAll->setStyleSheet("color: black");
    else
        ui->progAll->setStyleSheet("");
}
