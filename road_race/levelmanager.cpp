#include "levelmanager.h"
#include "gamemodel.h"
#include "squarelabel.h"
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
    if ( level == test ) {
        int o = 1;
        if ( o == 1 ) { contents = resourceFileContents("single-player"); }
        else { contents = resourceFileContents("sampleGame"); }
    }
    if (level == seven){
        contents = resourceFileContents("seven");
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
    return true;
    }
    else{
        return false;
    }
}
