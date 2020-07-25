#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include "about.h"
#include "sun.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddImage_clicked();
    void on_slotOpenImage_triggered();
    void on_clickBtn_clicked();
    void on_aboutBtn_clicked();
private:
    Ui::MainWindow *ui;
    QImage *image;
    About *about;
    Sun *sun;
};

#endif // MAINWINDOW_H
