#include "square.h"
#include "gamemodel.h"
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
void SquareLabel::mousePressEvent(QMouseEvent *ev){

    vector<vector<Square*>> squareList = Game::instance().getSquares();

    Square *proc = square;
    int x = this->x();
    if (proc->getOwner() == nullptr){
        int x = proc->getX();
        int y = proc->getY();
        int height = Game::instance().getHeight();
        int width = Game::instance().getWidth();
        QString owner;
        /*if((x-1) >0){
            Square *comp = Game::instance().getSquare(x+1,y);
            Player *newowner = comp->getOwner();
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
        }
        if((x+1) <= width){
            Square *comp = Game::instance().getSquare(x+1,y);
        }
        if((y-1) > 0){
            Square *comp = Game::instance().getSquare(x+1,y);
        }
        if((y+1) <= height){
            Square *comp = Game::instance().getSquare(x+1,y);
        */}

    else{
            QString owner;
            owner = QString::fromUtf8(proc->getOwner()->getName().c_str());
            this->setText(owner);
    }
    emit clicked();
}
