#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow // dwukropek oznacza dziedziczenie
{
    Q_OBJECT // jest to znacznik dla Qt który oznacza aby to potraktować specjalnie

public: // sekcja z publicznymi danymi
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); // tylda oznacza destruktor

private slots:
    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionundo_triggered();

    void on_actionNew_triggered();

    void on_actionSave_As_triggered();

private: // sekcja z prywatnymi danymi
    Ui::MainWindow *ui; // *ui jest wskaźnikiem do MainWindow
    void saveToFile(QString filePath);
};

#endif // MAINWINDOW_H
