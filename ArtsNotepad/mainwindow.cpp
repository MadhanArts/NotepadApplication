#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QFontDialog>
#include<QColorDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");

}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(file_name);
    filePath = file_name;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "File not Opened");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    // QString file_name = QFileDialog::getSaveFileName(this, "Save the file");
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "File not opened");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save As", QDir::currentPath(), "Text files (*.txt)");
    QFile file(file_name);
    filePath = file_name;
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "File not selected");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionselect_font_triggered()
{
    bool fontSelected;
    QFont myFont = QFontDialog::getFont(&fontSelected, this);
    if(fontSelected)
    {
        ui->textEdit->setFont(myFont);
    }
}

void MainWindow::on_actionfont_color_triggered()
{
    QColor myFontColor = QColorDialog::getColor(ui->textEdit->textColor(), this, "Select Font Color");
    if(myFontColor != nullptr)
    {
        ui->textEdit->setTextColor(myFontColor);
    }
}

void MainWindow::on_actionfont_background_color_triggered()
{
    QColor myFontBackgroundColor = QColorDialog::getColor(ui->textEdit->textBackgroundColor(), this, "Select Font Background Color");
    if(myFontBackgroundColor != nullptr)
    {
        ui->textEdit->setTextBackgroundColor(myFontBackgroundColor);
    }
}

void MainWindow::on_actionAbout_Ot_triggered()
{
    QMessageBox::information(this, "About Qt", "Qt is a framework, used to create GUI applications");
}

void MainWindow::on_actionbold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}

void MainWindow::on_actionitalic_triggered()
{
    ui->textEdit->setFontItalic(true);
}

void MainWindow::on_actionunderline_triggered()
{
    ui->textEdit->setFontUnderline(true);
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter p;
    p.setPrinterName("HP Laser Printer");
    QPrintDialog pd(&p, this);
    if(pd.exec()==QDialog::Rejected)
    {
        QMessageBox::warning(this,"Error","unable to access printer");
        return;
    }
    //ui->textEdit->print(&p);
}
