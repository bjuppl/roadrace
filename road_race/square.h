#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include "player.h"
#include <QMouseEvent>
#include <QGridLayout>
#include <QMainWindow>
#include <QHoverEvent>
#include <QWidget>

using namespace std;

class Player;
class Structure{
    //resprsent type of pathway
    string type;
    string image;
    //set owner

    Player *owner;
    //set owning Sqaure e.g. Square 3X4 has a road on it
public:
    Structure(string ntype, string nimage, Player* nowner): type(ntype), image(nimage), owner(nowner){}
    //set a square's path
    virtual void build() = 0;
    //destory the path, but not the square
    virtual void destroy() = 0;
    //destructor
    virtual ~Structure(){}
    string getType() { return type; }
    string getImage() { return image; }
    Player *getOwner() { return owner; }
    void setType(string nt){type = nt;}
    void setImage(string ni){image = ni;}
    void setOwner(Player *no){owner = no;}

};
class Boat: public Structure{

};
class Tunnel: public Structure{

};
class Wall: public Structure{

};
class Bridge: public Structure{

};

class Square{
    static int count;
    int id;
    string type;
    string image;
    Player *owner;
    string addition;
    Structure *path;
    int width, height;
    int x,y;
public:
    Square(string type_,string addition_,Player *owner_) : id(count), type(type_), image(type_), owner(owner_), addition(addition_) { count++; }
    Square(string type_,string addition_) : id(count), type(type_), image(type_), owner(NULL), addition(addition_) { count++; }
    Square(string type_) : id(count), type(type_), image(type_), owner(NULL), addition("") { count++; }
    Square(string type_,Player *owner_) : id(count), type(type_), image(type_), owner(owner_), addition("") { count++; }

    //TODO: make Square pure virtual with inherited types.
    //This will require updating in gamefile.cpp.
    //virtual bool mine()=0;
    //virtual bool destroy()=0;

    bool hasOwner () { return owner==NULL; }
    string getType() { return type; }
    string getImage() { return image; }
    Player *getOwner() { return owner; }
    string getAddition() { return addition; }
    int getHeight () { return height; }
    int getWidth () { return width; }
    std::string getResourceType();
    int getId() { return id; }

    void setType ( string t ) { type = t; }
    void setImage ( string i ) { image = i; }
    void setOwner ( Player *o ) { owner = o; }
    void setAddition ( string a ) { addition = a; }
    void setHeight ( int height_ ) { height = height_; }
    void setWidth ( int width_ ) { width = width_; }
    int getX(){return x;}
    int getY(){return y;}
    void setX(int nx){x = nx;}
    void setY(int ny){y = ny;}
};

class ForestSq: public Square{

};
class MountainSq: public Square{

};
class RiverSq: public Square{

};
class PlainSq: public Square{

};
class CanyonSq: public Square{

};

class SquareLabel : public QLabel{
    Q_OBJECT

    Square *square;
    bool mouseTracking;
    QFrame *frame;
    QPalette *color;
public:
    explicit SquareLabel (Square *square_, QWidget *parent): QLabel(parent), square(square_) {
        setMouseTracking(true);
        this->setAttribute(Qt::WA_Hover,true);
        connect(this,SIGNAL(clicked()),this,SLOT(labelClicked()));
    }
   void mousePressEvent(QMouseEvent *ev);
   void mouseMoveEvent(QMouseEvent *ev);
   void enterEvent(QHoverEvent *event);
   void leaveEvent(QHoverEvent *event);
   bool event(QEvent *e);
   QPixmap setmap(string image);
   void setFrame(QFrame *f){
       frame = f;
   }
   void setColor(QPalette *p){
       color = p;
   }
   QPalette* getColor(){return color;}
   QFrame* getFrame(){return frame;}
   ~SquareLabel(){
       delete frame;
       delete color;
   }

private slots:
    void labelClicked(){

    }

signals:
    void clicked();
    void hovered();

};




#endif // SQUARE_H
