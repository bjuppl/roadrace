#include "levelmanager.h"
#include "gamemodel.h"
#include "squarelabel.h"
#include "network.h"
#include <random>
#include <QMessageBox>
#include <QDebug>
int random_int1(int min, int max) {
    static std::default_random_engine engine { std::random_device{}() };
    std::uniform_int_distribution<int> distro{min, max};
    return distro(engine);
}
LevelManager *LevelManager::instance_ = nullptr;

LevelManager& LevelManager::instance() {
    if (instance_ == nullptr ) {
        instance_ = new LevelManager();
    }

    return *instance_;
}

std::vector<std::string> LevelManager::getLevel(int num) {
    std::vector<std::string> contents;
    return contents;

}

std::vector<std::string> LevelManager::getLevel(std::string level ) {
    std::vector<std::string> contents;
    const std::string test = "test";
    const std::string seven = "seven";
    const std::string random = "randomfile";
    if ( level == test ) {
        int o = 1;
        if ( o == 1 ) { contents = resourceFileContents("single-player"); }
        else { contents = resourceFileContents("sampleGame"); }
    }
    if (level == seven){
        contents = resourceFileContents("seven");
    }
    if (level == random){

        contents = LevelManager::instance().randWorld();
    }
    return contents;

}

std::vector<std::string> LevelManager::resourceFileContents(std::string alias ) {
    QFile file(QString::fromStdString(":/" + alias));
    std::vector<std::string> ret;
    if(file.open(QFile::ReadOnly)) {
        QTextStream conts(&file);

        while(!conts.atEnd()) {
            QString ln = conts.readLine();
            ret.push_back(ln.toStdString());
        }

        file.close();

        return ret;

    } else {
        std::cerr << "Failed to read resource file: '" << alias << "'. " << std::endl;

        return ret;
    }
}
string LevelManager::upRec(int goodRes){
    string result;
    if(goodRes == 0){
        int wood = Game::instance().getCurPlayer()->getWood();
        wood += 50;
        Game::instance().getCurPlayer()->setWood(wood);
        result = "wood";
        return result;
    }
    if(goodRes == 1){
        int gold = Game::instance().getCurPlayer()->getGold();
        gold += 50;
        Game::instance().getCurPlayer()->setGold(gold);
        result = "gold";
        return result;
    }
    if(goodRes == 2){
        int water = Game::instance().getCurPlayer()->getWater();
        water += 50;
        Game::instance().getCurPlayer()->setWater(water);
        result = "water";
        return result;
    }
    if(goodRes == 3){
        int stone = Game::instance().getCurPlayer()->getStone();
        stone += 50;
        Game::instance().getCurPlayer()->setStone(stone);
        result = "stone";
        return result;
    }
}
string LevelManager::downRec(int badRes){
    string result;
    if(badRes == 0){
        int wood = Game::instance().getCurPlayer()->getWood();
        wood -= 50;
        Game::instance().getCurPlayer()->setWood(wood);
        result = "wood";
        return result;
    }
    if(badRes == 1){
        int gold = Game::instance().getCurPlayer()->getGold();
        gold -= 50;
        Game::instance().getCurPlayer()->setGold(gold);
        result = "gold";
        return result;
    }
    if(badRes == 2){
        int water = Game::instance().getCurPlayer()->getWater();
        water -= 50;
        Game::instance().getCurPlayer()->setWater(water);
        result = "water";
        return result;
    }
    if(badRes == 3){

        int stone = Game::instance().getCurPlayer()->getStone();
        stone -= 50;
        Game::instance().getCurPlayer()->setStone(stone);
        result = "stone";
        return result;
    }
}
bool LevelManager::killStruct(int hit, int wid){
    Square *victim = Game::instance().getSquare(wid,hit);
    if (victim->getAddition()!= "No"){
    Structure *killStruct = Game::instance().getStructure("Ru");
    victim->setStruct(killStruct);
    victim->setAddition("No");
    SquareLabel *vicLbl = victim->getLabel();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSize()/2;
     QSize size1(size,size);
    vicLbl->setPixmap(GuiManager::instance().setmap(victim,size1));
    string result;
    result = "Destroyed Struct";
    string details;
    details += to_string(wid) + " " + to_string(hit) + " " + victim->getAddition();
    Network::instance().ActionReciever(result,details);
    return true;
    }
    else{
        return false;
    }
}
bool LevelManager::riverSquare(int hit, int wid){
    Square *victim = Game::instance().getSquare(wid,hit);
    Structure *killStruct = Game::instance().getStructure("Ru");
    if(victim->getImage() != "Ri"){
    victim->setStruct(killStruct);
    victim->setAddition("No");
    victim->setType("Ri");
    victim->setImage("Ri");
    SquareLabel *vicLbl = victim->getLabel();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSize()/2;
     QSize size1(size,size);
    vicLbl->setPixmap(GuiManager::instance().setmap(victim,size1));
    string action = "Change type";
    string details;
    details += to_string(wid) + " " + to_string(hit) + " " + victim->getType();
    Network::instance().ActionReciever(action,details);
    return true;
    }
    else{
        return false;
    }
}
bool LevelManager::burnSquare(int hit, int wid){
    Square *victim = Game::instance().getSquare(wid,hit);
    Structure *killStruct = Game::instance().getStructure("Ru");
    if(victim->getImage() != "Pl"){
    victim->setStruct(killStruct);
    victim->setAddition("No");
    victim->setType("Pl");
    victim->setImage("Pl");
    SquareLabel *vicLbl = victim->getLabel();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSize()/2;
     QSize size1(size,size);
    vicLbl->setPixmap(GuiManager::instance().setmap(victim,size1));
    string action = "Change type";
    string details;
    details += to_string(wid) + " " + to_string(hit) + " " + victim->getType();
    Network::instance().ActionReciever(action,details);
    return true;
    }
    else{
        return false;
    }
}
bool LevelManager::quakeSquare(int hit, int wid){
    Square *victim = Game::instance().getSquare(wid,hit);
    Structure *killStruct = Game::instance().getStructure("Ru");
    if(victim->getImage() != "Ca"){
    victim->setStruct(killStruct);
    victim->setAddition("No");
    victim->setType("Ca");
    victim->setImage("Ca");
    SquareLabel *vicLbl = victim->getLabel();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSize()/2;
     QSize size1(size,size);
    vicLbl->setPixmap(GuiManager::instance().setmap(victim,size1));
    return true;
    }
    else{
        return false;
    }
}
bool LevelManager::eruption(int hit, int wid){
    Square *victim = Game::instance().getSquare(wid,hit);
    Structure *killStruct = Game::instance().getStructure("Ru");
    if(victim->getImage() != "Ri" && victim->getOwner() != nullptr){
    victim->setStruct(killStruct);
    victim->setAddition("No");
    SquareLabel *vicLbl = victim->getLabel();
    int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/Game::instance().getSize()/2;
    QSize size1(size,size);
    vicLbl->setPixmap(GuiManager::instance().setmap(victim,size1));
    burn = victim->getResourceType();
    Game::instance().setVPos(wid,hit);
    victim->setBurn(true);
    string action = "Change type";
    string details;
    details += to_string(wid) + " " + to_string(hit) + " " + victim->getType();
    Network::instance().ActionReciever(action,details);
    return true;
    }
    else{
        return false;
    }
}
vector<string> LevelManager::randWorld(){
    //ofstream stream("random2.rr");
    vector<string> contents;
    contents.push_back("RoadRaceDoc");
    contents.push_back("00000000000");
    contents.push_back("alias Name none Password Irrelevant");
    contents.push_back("round 1");
    contents.push_back("players me");
    contents.push_back("info me resources Go,0 Wa,0 Sto,0 Wo,0 status score,00000000 start_time,0000000");
    int randHgt = random_int1(5,7);
    int randWid = randHgt;
    int lol = randHgt;
    contents.push_back("board " + to_string(lol) + "," + to_string(randWid));
    contents.push_back("Ca,Br,me Fo,No,No");
    int comp = (randHgt-2);
    int index = 0;
    string sqstr;
    while(index < comp){

        int typeint = random_int1(0,5);
        if(typeint == 0){
            sqstr += " Pl,No,No";
        }
        else if (typeint == 1){
            sqstr += " Fo,No,No";
        }
        else if (typeint == 2){
            sqstr += " Ri,No,No";
        }
        else if (typeint == 3){
            sqstr += " Ca,No,No";
        }
        else if (typeint == 4){
            sqstr += " Mo,No,No";
        }
        else if (typeint == 5){
            sqstr += " Sw,No,No";
        }
        index++;
    }
    contents.push_back(sqstr);
    sqstr = "";
    index = 1;
    bool volcano = false;
    while(index < randHgt){
        int index2 = 0;

        while(index2 < randWid){
            int typeint = random_int1(0,6);
            if (index == (randHgt-1) && index2 == (randWid-1)){
                sqstr += "Wi,No,No";
                break;
            }
            if(typeint == 0){
                sqstr += "Pl,No,No ";
            }
            else if (typeint == 1){
                sqstr += "Fo,No,No ";
            }
            else if (typeint == 2){
                sqstr += "Ri,No,No ";
            }
            else if (typeint == 3){
                sqstr += "Ca,No,No ";
            }
            else if (typeint == 4){
                sqstr += "Mo,No,No ";
            }
            else if (typeint == 5){
                sqstr += "Sw,No,No ";
            }
            else if (typeint == 6){
                if(volcano == false){
                sqstr += "La,No,No ";
                volcano = true;
                }
                else{
                    sqstr += "Mo,No,No ";
                }
            }


            index2++;
        }
        index++;
        contents.push_back(sqstr);
        sqstr = "";
    }

    contents.push_back("EndRoadRaceDoc");
    return contents;
    //ofstream ranFile("random.rr");

    //ranFile << contents.c_str();
    //ranFile.close();
    //stream << contents;
    //stream.close();
}

void LevelManager::trader(){
    int gold = Game::instance().getCurPlayer()->getGold();
    int wood = Game::instance().getCurPlayer()->getWood();
    int stone = Game::instance().getCurPlayer()->getStone();
    int water = Game::instance().getCurPlayer()->getWater();

    if (wood >= 50 && wood > gold){
        QMessageBox::StandardButton trade;
        trade = QMessageBox::question(GuiManager::instance().getUi()->gridLayoutWidget,"Hello there.","I see you have alot of wood. Would you like to trade 50 of it for 25 gold?",QMessageBox::Yes|QMessageBox::No);
        if(trade == QMessageBox::Yes){

            wood -= 50;
            gold += 25;
            Game::instance().getCurPlayer()->setGold(gold);
            Game::instance().getCurPlayer()->setWood(wood);
        }
        else if(water > 100 && water > stone){
            QMessageBox::StandardButton trade;
            trade = QMessageBox::question(GuiManager::instance().getUi()->gridLayoutWidget,"Hello there.","I see you have alot of water. Would you like to trade 100 of it for 75 stone?",QMessageBox::Yes|QMessageBox::No);
            if(trade == QMessageBox::Yes){

                water -= 100;
                stone += 75;
                Game::instance().getCurPlayer()->setStone(stone);
                Game::instance().getCurPlayer()->setWater(water);
            }
        }
    }

}
void LevelManager::prepSquares(QString str){
    string proc = str.toStdString();
    vector<string> proc1 = split(proc,' ');
    int index = 1;
    vector<string> squarevec;
    while(index < proc1.size()){
        if(proc1.at(index) == "board"){
            int i2 = index;
            while(i2 < proc1.size()){
                squarevec.push_back(proc1.at(i2));
                i2++;
            }
            break;
        }
        index++;
    }
    string sizestr = squarevec.at(1);
    string str1;
    string str2;
    qDebug() << QString::fromStdString(sizestr);
    str1 += sizestr.at(0);
    str2 += sizestr.at(2);
    int x = stoi(str1);
    int y = stoi(str2);
    Game::instance().setWidth(x);
    Game::instance().setHeight(y);
    vector<vector<Square*>> squares;
    int i3 =1;
    int index2 = 0;
    int dd = squarevec.size();
    squarevec.erase(squarevec.begin());
     while(index2 < squarevec.size()){
         vector<Square*> minivec;
         int i4 = 0;
         while(i4 < y){
             QString debugStr = "DEBUG: " + QString::fromStdString(squarevec.at(i3));
             qDebug() << debugStr;
             vector<string> squarestrs = split(squarevec.at(i3),',');
             if(squarevec.at(i3) != "EndRoadRaceDoc"){
                 if(squarestrs.at(2) == "No"){
             minivec.push_back(new Square(squarestrs.at(0),squarestrs.at(1),nullptr));
                 }
                 else{
                     string ownerName = squarestrs.at(2);
                     Player *owner = Game::instance().getPlayer(ownerName);
                     if(owner == nullptr){
                         vector<Player*> players = Game::instance().getPlayerList();
                         owner = new Player(ownerName);
                         players.push_back(owner);
                         Game::instance().setPlayerList(players);
                         qDebug() << "Name" + QString::fromStdString(ownerName);
                     }
                     minivec.push_back(new Square(squarestrs.at(0),squarestrs.at(1),owner));
                 }
             }
             else{
                 index2 = squarevec.size();
                 break;
             }
             i3++;
             i4++;
         }
         squares.push_back(minivec);
         index2++;
     }
     Game::instance().setSquares(squares);
     GuiManager::instance().generateSquareGrid();
    }
