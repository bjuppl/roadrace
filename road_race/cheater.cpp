#include "cheater.h"
#include "ui_cheater.h"
#include "player.h"
#include "gamemodel.h"
#include <QLineEdit>
#include <string>
#include "levelmanager.h"
cheater::cheater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cheater)
{
    ui->setupUi(this);
}

cheater::~cheater()
{
    delete ui;
}

void cheater::on_canBtn_clicked()
{

    this->hide();
}

void cheater::on_yesBtn_clicked()
{
    Player *proc = Game::instance().getCurPlayer();
    int wod = proc->getWood();
    int wa = proc->getWater();
    int go = proc->getGold();
    int sto = proc->getStone();
    if(ui->woodBox->text()!= nullptr){
    string wo = ui->woodBox->text().toStdString();
    wod += stoi(wo,0,10);
    proc->setWood(wod);
    }
    if(ui->waBOx->text() != nullptr){
    string was = ui->waBOx->text().toStdString();
    wa += stoi(was);
     proc->setWater(wa);
    }
    if(ui->goBox->text() != nullptr){
    string got = ui->goBox->text().toStdString();
    go += stoi(got);
     proc->setGold(go);
    }
    if(ui->stoBox->text() != nullptr){
    string stot = ui->stoBox->text().toStdString();
    sto = stoi(stot);
    proc->setStone(sto);
    }
    this->hide();
}


void cheater::on_RndBox_toggled(bool checked)
{
    if (checked){
        LevelManager::instance().setRand(false);
    }
}
