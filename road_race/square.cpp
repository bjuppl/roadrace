#include "square.h"
#include "gamemodel.h"
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>

int Square::count = 0, Square::size = 0, Square::border = 0;

std::string Square::getResourceType() {
    // Pl = plain, Ri = river, Mo = mountain, Fo = forest, Ca = canyon
    if ( type == "Pl") {
        return "";
    } else if ( type == "Ri" ) {
        return "Wa";
    } else if ( type == "Mo" ) {
        return "St";
    } else if ( type == "Fo" ) {
        return "Wo";
    } else if ( type == "Ca") {
        return "Go";
    } else {
        return "";
    }
}
<<<<<<< HEAD



/*void SquareLabel::mousePressEvent(QMouseEvent *ev){

    vector<vector<Square*>> squareList = Game::instance().getSquares();
   int i = squareList.size();
    Square *proc = square;
    int x2 = this->x();
    if (proc->getOwner() == nullptr){
        int x = proc->getX();
        int y = proc->getY();
        int height = Game::instance().getHeight();
        int width = Game::instance().getWidth();
        int y2 = (y-2);

        QString owner;
        if((x-1) == 0){
            Square *c1;
            Square *c2;
            Square *c3;
            vector<Square*> list1;
            vector<Square*> list2;
            vector<Square*> list3;
            Player *newowner;
            if(y > 0 && y != squareList.size()){
             list1 = squareList.at(y);
             list2 = squareList.at(y2);
             c1 = list1.at(0);
              c2 = list2.at(0);
              c3 = list1.at(1);
            }
            else{
                list2 = squareList.at(y2);
                list3 = squareList.at(y-1);
                c1=nullptr;
                c2 = list2.at(0);
                c3 = list3.at(1);
            }
            if((c1!= nullptr) && (c1->getOwner() != nullptr)){
                newowner = c1->getOwner();
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr)){
                newowner = c2->getOwner();
            }
            else if(c3->getOwner() != nullptr){
                newowner = c3->getOwner();
            }
            c1=nullptr;
            c2=nullptr;
            c3=nullptr;
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
        }
        else if(x == width){
            Square *c1;
            Square *c2;
            Square *c3;
            vector<Square*> list1;
            vector<Square*> list2;
            vector<Square*> list3;
            Player *newowner;
            if(y > 0 && y != squareList.size()){
             list1 = squareList.at(y);
             if(y2 >= 0){
             list2 = squareList.at(y2);
              c2 = list2.at(x-1);
             }
             c1 = list1.at(x-1);
             c3 = list1.at(x-2);
            }
            else{
                list2 = squareList.at(y2);
                list3 = squareList.at(y-1);
                c1=nullptr;
                c2 = list2.at(x-1);
                c3 = list3.at(x-2);
            }
            if((c1!= nullptr) && (c1->getOwner() != nullptr)){
                newowner = c1->getOwner();
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr)){
                newowner = c2->getOwner();
            }
            else if(c3->getOwner() != nullptr){
                newowner = c3->getOwner();
            }
            c1=nullptr;
            c2=nullptr;
            c3=nullptr;
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
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
void SquareLabel::mouseMoveEvent(QMouseEvent *ev){

}
QPixmap SquareLabel::setmap(string image){


    if(image == "Fo"){
        QPixmap map(":/forrest");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);

        return result;
    }
    if(image == "Ca"){
        QPixmap map(":/canyon");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Ri"){
        QPixmap map(":/water");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if (image == "Mo"){
        QPixmap map(":/mountain");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Pl"){
        QPixmap map(":/grass");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
}
void SquareLabel::enterEvent(QHoverEvent *event){

          if(square->getOwner() != nullptr){
            QString owner = QString::fromUtf8(square->getOwner()->getName().c_str());
            this->setText(owner);
          }
          else{
              this->setText("Unowned");
          }
}
void SquareLabel::leaveEvent(QHoverEvent *event){
    QPixmap map = setmap(square->getImage());

           this->setPixmap(map);
}

bool SquareLabel::event(QEvent *e){
    switch(e->type()){
    case QEvent::HoverEnter:
        enterEvent(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
         leaveEvent(static_cast<QHoverEvent*>(e));
         return true;
         break;
    default:
        break;
    }
    return QWidget::event(e);
}
bool Square::canGet(Square *prev){
    if (this->getType() == "Ri"){
        if(prev->getAddition() == "Bo"){
            return true;
        }
        else{
            return false;
        }
    }
    if(this->getType() == "Mo"){
        if(prev->getAddition() == "Tu"){
            return true;
        }
        else{
            return false;
        }
    }
    if(this->getType() == "Ca"){
        if(prev->getAddition() == "Br"){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }

}
*/
=======
>>>>>>> upstream/master
