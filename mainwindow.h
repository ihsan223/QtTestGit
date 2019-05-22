#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionClose_triggered();

    void on_actionOpen_triggered();

    void ShowImage(QString filePath, qreal rotate);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
