#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->image = new QImage();

        //connect the button listener event
//         connect(ui->AddImage,SIGNAL(clicked()), this, SLOT(on_slotOpenImage_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_aboutBtn_clicked
 *
 * Have Some bug cannot solve. When close main widge, the about and sun will not auto closed,
 * unlesss you close it by yourself.
 */

void MainWindow::on_aboutBtn_clicked()
{
    About *newLog = new About();
    newLog->setWindowTitle("About");
    newLog->setStyleSheet("background-color: white;");
//    newLog->move(200, 200);
    ui->clickBtn->setText("Clicked");
    newLog->show();
}


void MainWindow::on_clickBtn_clicked()
{
   Sun *sun = new Sun();
   sun->setWindowTitle("北京的金山上光芒照四方");
   sun->setStyleSheet("background-color: white;");
//   sun->move(200, 350);
   sun->show();

}


void MainWindow::on_AddImage_clicked()
{
    this->on_slotOpenImage_triggered();
}

void MainWindow::on_slotOpenImage_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "open image file",
                ".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    if(fileName != "")
    {
        if(image->load(fileName))
        {
            QGraphicsScene *scene = new QGraphicsScene;

            //判断原图的大小是否超过了显示区域的大小，1则按照倍数缩放，以宽度为准。
            double imgWidth = image->width();
            double viewWidth = ui->graphicsView->width();
            double scale = viewWidth/imgWidth;
//            QString str = QString::number(scale);
//            ui->clickBtn->setText(str);
            QImage newImage = image->scaled(image->width()*scale, image->height()*scale);
            scene->addPixmap(QPixmap::fromImage(newImage));
//            QGraphicsView *graphicsView = new QGraphicsView();
            ui->graphicsView->setScene(scene);
//            ui->graphicsView->resize(image->width() + 10, image->height() + 10);
//            ui->graphicsView->show();
        }
    }
}




