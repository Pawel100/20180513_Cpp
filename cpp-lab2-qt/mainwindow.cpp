#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionNew_triggered()
{
    m_FilePath = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "File has not been opened");
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
}

void MainWindow::saveToFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }

    QTextStream out(&file);
    //out << ui->textEdit->toPlainText();
    out << ui->textEdit->toHtml();
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    if (m_FilePath == "") {
        m_FilePath = QFileDialog::getSaveFileName(this, "Save the file");
    }

    saveToFile(m_FilePath);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save the file");
    saveToFile(filePath);

    m_FilePath = filePath; //?
}
