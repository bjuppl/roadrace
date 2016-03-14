#include "title.h"
#include "ui_title.h"

title::title(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::title)
{
    ui->setupUi(this);
}

title::~title()
{
    delete ui;
}

void title::on_titleButton_2_clicked()
{
    first = false;
    this->hide();
}
