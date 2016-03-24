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
    if(ui->woodBox->toPlainText()!= nullptr){
    string wo = ui->woodBox->toPlainText().toStdString();
    wod += stoi(wo,0,10);
    proc->setWood(wod);
    }
    if(ui->waBOx->toPlainText() != nullptr){
    string was = ui->waBOx->toPlainText().toStdString();
    wa += stoi(was);
     proc->setWater(wa);
    }
    if(ui->goBox->toPlainText() != nullptr){
    string got = ui->goBox->toPlainText().toStdString();
    go += stoi(got);
     proc->setGold(go);
    }
    if(ui->stoBox->toPlainText() != nullptr){
    string stot = ui->stoBox->toPlainText().toStdString();
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
