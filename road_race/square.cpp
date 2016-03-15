#include "square.h"
#include "gamemodel.h"
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
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
        if((x-1) == 0){
            Square *comp = Game::instance().getSquare(x+1,y);
            Player *newowner = comp->getOwner();
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
        }
        else if((x+1) <= width){
            Square *comp = Game::instance().getSquare(x-1,y);
            Square *comp2;
            Square *comp3;
            Player *newowner;
            if(Game::instance().getSquare(x,y+1) != nullptr){
              comp2 = Game::instance().getSquare(x,y+1);
            }
            if(Game::instance().getSquare(x,y-1) != nullptr){
             comp3 = Game::instance().getSquare(x,y-1);
            }
            if(comp->getOwner() != nullptr){
            newowner = comp->getOwner();
            }
            else if (comp2->getOwner() != nullptr){
                newowner = comp2->getOwner();
            }
            else {
                newowner = comp3->getOwner();
            }
            if (newowner != nullptr){
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
            }
            else{
                 QMessageBox::information(this,"Alert","You cannot claim this square!",0,1);
            }
        }
        else if((y-1) > 0){
            Square *comp = Game::instance().getSquare(x+1,y);
        }
        else if((y+1) <= height){
            Square *comp = Game::instance().getSquare(x+1,y);
             }
        this->setText(owner);
    }

    else{
            QString owner;
            owner = QString::fromUtf8(proc->getOwner()->getName().c_str());
            this->setText(owner);
    }
    emit clicked();
}
