#include "cheater.h"
#include "ui_cheater.h"
#include "player.h"
#include "gamemodel.h"
#include <QLineEdit>
#include <string>
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
    string wo = ui->woodBox->toPlainText().toStdString();
    wod += stoi(wo);
    string was = ui->waBOx->toPlainText().toStdString();
    wa += stoi(was);
    string got = ui->goBox->toPlainText().toStdString();
    go += stoi(got);
    string stot = ui->stoBox->toPlainText().toStdString();
    sto = stoi(stot);
    proc->setWood(wod);
    proc->setWater(wa);
    proc->setGold(go);
    proc->setStone(sto);
    this->hide();
}

