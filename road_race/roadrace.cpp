#include "roadrace.h"
#include "ui_roadrace.h"

RoadRace::RoadRace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoadRace)
{
    ui->setupUi(this);
}

RoadRace::~RoadRace()
{
    delete ui;
}
