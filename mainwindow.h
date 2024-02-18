#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void void_();

private slots:

    void on_addImageButton_clicked();
    void on_quitAddStudentButton_clicked();

    void on_addStudentButton_clicked();

    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void on_lineEdit_20_cursorPositionChanged(int arg1, int arg2);

    void on_searchButton_clicked();

    void on_pushButton_clicked();

    void on_deleteStudentButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
