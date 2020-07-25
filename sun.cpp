#include "sun.h"
#include "ui_sun.h"

Sun::Sun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sun)
{
    ui->setupUi(this);
}

Sun::~Sun()
{
    delete ui;
}
