#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), // jest to lista inicjalizacyjna, tutaj mały wywołanie konstrukota klasy nadrzednej
    ui(new Ui::MainWindow) // tutaj mamy alokację pamięci na stercie, koniec tej listy inicjalizacyjnej
{
    ui->setupUi(this); // oznacza to inicjalizację interfejsu, setupUi analizuje mainwindow.ui i coś wyrysowywuje
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui; // zwalnianie pamięciu gdzie ui jest wskaźnikiem do tego co ma być usunięte
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionundo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionNew_triggered()
{
    //ui->textEdit->clear();
    ui->textEdit->setText("");
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save the file");
        saveToFile(filePath);
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
