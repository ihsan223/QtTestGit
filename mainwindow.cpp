#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));

    QStringList *list = new QStringList();
    QString a("1");
    list->append(a);
    list->append("2");
    list->append("3");
    list->append("4");
    ui->comboBox->addItems(*list);
    delete list;
    list = nullptr;

    ui->comboBox->clear();
    ui->comboBox->addItem(QIcon("D:/QTProjects/TestQT/close.png"), "Close");
    ui->comboBox->addItem(QIcon("D:/QTProjects/TestQT/open.png"), "Open");

    // disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
    //            ui->progressBar, SLOT(setValue(int)));

    /*QPixmap pix("C:\\Users\\IhsanCelik\\Desktop\\Kişisel\\1.jpeg");

    int width = ui->labelPicture->width();
    int height = ui->labelPicture->height();
    QMatrix matrix;
    matrix.rotate(270);
    auto img = pix.transformed(matrix, Qt::TransformationMode::FastTransformation)
            .scaled(width,height, Qt::KeepAspectRatio);
    ui->labelPicture->setPixmap(img);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply =
            QMessageBox::question(this, "Hello","Esselamun!", QMessageBox::Yes|QMessageBox::No);


    if(reply == QMessageBox::Yes)
    {
        QMessageBox::information(this, "yes","yes");
        QString comboBoxCurrentText( ui->comboBox->currentText());
        QMessageBox::information(this, comboBoxCurrentText, comboBoxCurrentText);
    }
    else if(reply == QMessageBox::No)
    {
        QMessageBox::information(this,"No","No");
    }
    else
    {
        QMessageBox::information(this,"Other","Other");
    }
}

void MainWindow::on_actionClose_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg *.jpeg)"));
    dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;

    if(dialog.exec())
        fileNames = dialog.selectedFiles();

    if(fileNames.count() > 0)
        ShowImage(fileNames[0], 33);
}

void MainWindow::ShowImage(QString filePath, qreal rotate)
{
    QPixmap pix(filePath);
    QMatrix matrix;
    matrix.rotate(rotate);
    bool truem(true);
    matrix.inverted(&truem);

    int width = ui->labelPicture->width();
    int height = ui->labelPicture->height();

    ui->labelPicture->setPixmap(pix.scaled(width, height, Qt::AspectRatioMode::KeepAspectRatio).transformed(matrix));
}











