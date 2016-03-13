#include "gui.h"
#include "roadrace.h"
#include "gamemodel.h"
GuiManager *GuiManager::instance_ = NULL;

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

void GuiManager::generateSquareGrid() {
    std::cout << getUi()->label->text().toStdString() << std::endl;
    int hi = Game::instance().getHeight();
    int wi = Game::instance().getWidth();
    vector<vector<Square*>> squaresList = Game::instance().getSquares();
    vector<Square*> squares = squaresList.at(0);
    int index = 0;
    for(index = 0;index<squares.size();index++){
       Square *proc = squares.at(index);
       SquareLabel *lbl = new SquareLabel(proc,ui->gridLayoutWidget);
       QPixmap map = setmap(proc);
       lbl->setPixmap(map);
       ui->gameLayout->addWidget(lbl,0,0,0,0,0);
       lbl->show();
    }

}

QPixmap GuiManager::setmap(Square *sq){
    string image = sq->getImage();

    if(image == "Fo"){
        QPixmap result(":/forrest");
        return result;
    }
    if(image == "Ca"){
        QPixmap result(":/canyon");
        return result;
    }
    if(image == "Ri"){
        QPixmap result(":/water");
        return result;
    }
    if (image == "Mo"){
        QPixmap result(":/mountain");
        return result;
    }
    if(image == "Pl"){
        QPixmap result(":/grass");
        return result;
    }
}
