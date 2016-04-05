#include <string>
#include <iostream>
#include <istream>
#include <random>
#include <QMessageBox>
#include "gamemodel.h"
#include "gui.h"
#include "player.h"
#include "square.h"
#include "levelmanager.h"
#include "network.h"
#include "sound.h"
using namespace std;

class Player;
int random_int(int min, int max) {
    static std::default_random_engine engine { std::random_device{}() };
    std::uniform_int_distribution<int> distro{min, max};
    return distro(engine);
}
Game *Game::instance_ = NULL;
Updater *Updater::instance_ = NULL;

Game::Game() {
    vector<Resource*> rl;


    vector<Structure*> sl;
    //Bo = boat, Br = bridge, Wa = wall, Tu = tunnel
    vector<Price> a = {Price("Wo",100),Price("St",50)};
    sl.push_back(new Structure("boat","Bo",a));
    vector<Price> b = {Price("Wo",200),Price("St",100)};
    sl.push_back(new Structure("bridge","Br",b));
    vector<Price> c = {Price("Wo",50),Price("St",300)};
    sl.push_back(new Structure("wall","Wa",c));
    vector<Price> d = {Price("Wa",50),Price("Go",100),Price("St",50)};
    sl.push_back(new Structure("tunnel","Tu",d));
    vector<Price> e = {Price("Go",100),Price("Wa",75)};
    sl.push_back(new Structure("deforest","De",e));
    vector<Price> f = {Price("",0)};
    sl.push_back(new Structure("ruins","Ru",f));
    vector<Price> g = {Price("Wa",150),Price("Go",200),Price("St",200)};
    sl.push_back(new Structure("drained","Cl",g));
    vector<Price> h = {Price("Wa",200),Price("St",200),Price("Wo",200)};
    sl.push_back(new Structure("hardened","Ha",h));
    structure_types = sl;

}

void Game::start(){
    Updater::instance().start();

}

void Game::updateResources() {
    string type;
    string name;
    vector<string> signalstrs;
    for ( size_t i=0; i<player_list.size(); i++ ) {
        vector<Square*> mysquares;

        Player *p = player_list[i];
        name = p->getName();
        mysquares = getPlayerSquares(p);
        type = "";
        for ( size_t j=0; j<mysquares.size(); j++ ) {
            if(mysquares.at(j)->getType() != "Wi")
            {
                std::string rtype = mysquares.at(j)->getResourceType();
                int add = getResource(rtype)->value;
                string resourceInt;
                resourceInt = to_string(p->getResource(rtype));
                type += " "+ rtype + " " + resourceInt;
                p->incResource(rtype, add);
            }

        }
        if(Game::instance().getIsLocalGame() == true){
            string action = "New Sources";
            string details = p->getName();
            details += type;
            string signal = Network::instance().ActionReciever(action,details);
            signalstrs.push_back(signal);
        }
    }
   /* if(signalstrs.size() > 0){
        int i = 0;
        while (i < signalstrs.size()){
            QString sendstr = QString::fromStdString(signalstrs.at(i));
            GuiManager::instance().getWindow()->actionSender(sendstr);
            i++;
        }
    }*/
}

vector<Square*> Game::getPlayerSquares(Player *owner) {
    vector<Square*> list;

    if ( owner == NULL ) {
        return list;
    }
    for ( size_t i=0; i<squares.size(); i++ ) {
        for ( size_t j=0; j<squares[i].size(); j++ ) {
            if (squares[i][j]->getOwner() != NULL && squares[i][j]->getOwner()->getName() == owner->getName() ) {
                list.push_back(squares[i][j]);

            }
        }
    }

    return list;
}



//used for construction of bridges/roads
bool buildCommand::execute(){
    return true;
}

Game::~Game() {
    for ( size_t i=0; i<player_list.size(); i++ ) {
        delete player_list[i];
    }
    for ( size_t i=0; i<squares.size(); i++ ) {
        for ( size_t j=0; j<squares.at(i).size(); j ++ ) {
            delete squares[i][j];
        }
    }
    for ( size_t i=0; i<resource_types.size(); i++ ) {
            delete resource_types.at(i);
    }

}

//save the game by writing to a file
bool Game::save(){
    return true;
}

//load a previous game state
string Game::load(){
    return "string";
}

//update the game world
void Game::update(){
    Game::instance().updateResources();
    GuiManager::instance().fillResourceList();
    GuiManager::instance().setTimeBox( Updater::instance().getDuration()/1000 );
    int x = Updater::instance().getTime();
    x++;
    if(x == 9){
        if(Game::instance().getVx() != 444){
        Game::instance().getSquare(Game::instance().getVx(),Game::instance().getVy())->setBurn(false);
        }
        x = 0;
        Updater::instance().setTime(x);
    }
    else{
        Updater::instance().setTime(x);
    }
}

bool Game::applyCommand(string command) {
    std::vector<std::string> itms;
    itms = split(command,' ');

    std::string identifier = itms[0];

    const std::string scores = "scores",
            start = "start",
            end = "end";
    if ( identifier == scores) {

    } else if ( identifier == start ) {

    } else if ( identifier == end ) {

    } else {

    }

    return true;
}

Game& Game::instance() {
    if (instance_ == NULL ) {
        instance_ = new Game();
    }
    return *instance_;
}
void Updater::start(){
    timer->start(interval_ms);
    started_at = time.currentMSecsSinceEpoch();
    eventTime->start(30000);
}

void Updater::stop() {
    timer->stop();
    duration = time.currentMSecsSinceEpoch() - started_at;
    eventTime->stop();
}

Updater& Updater::instance() {
    if (instance_ == NULL ) {
        instance_ = new Updater();
    }
    return *instance_;
}

void Game::purchaseAddition(Square *source) {

}

void Game::setGameLoader(GameFileManager *gfm) {
    //delete gfm;
    loader = gfm;
}

Player *Game::getPlayer(string name){

    for ( size_t i=0; i<player_list.size(); i++ ) {
        if ( player_list[i]->getName() == name   ) {
            return player_list[i];
        }
    }

    return NULL;
}

Resource *Game::getResource(string shortName) {
    for ( size_t i=0; i<resource_types.size(); i++ ) {
        if ( resource_types[i]->shortName == shortName ) {
            return resource_types[i];
            cout<<"ok";
        }
    }
    return nullptr;
}

Structure *Game::getStructure(string shortName) {
    for ( size_t i=0; i<structure_types.size(); i++ ) {
        if ( structure_types[i]->shortName == shortName ) {
            return structure_types[i];
        }
    }
    return nullptr;
}

Square *Game::getSquare(int id) {
   for (size_t i=0; i<squares.size(); i++ ) {
         for ( size_t j=0; j<squares.at(i).size(); j++ ) {
            if (squares.at(i).at(j)->getId() == id ) {
                return squares.at(i).at(j);
            }
        }
   }

  return nullptr;
}


void Game::setSquares ( vector<vector<Square*>> sq ) {
    for ( size_t i=0; i<squares.size(); i++ ) {
        for (size_t j=0; j<squares.at(i).size(); j++ ) {
            delete squares[i][j];
        }
    }
    squares = sq;
}


void Game::setResources(vector<Resource *> vr) {
    for ( size_t i=0; i< resource_types.size(); i++ ) {
            delete resource_types[i];
    }
    resource_types = vr;
}
void Updater::eventrun(){
    if (LevelManager::instance().getRand()){
        int random = random_int(0,7);

        if(random == 0){
          //spontaneously give a player 50 of a resource
            int goodInt = random_int(0,3);
            string recType = LevelManager::instance().upRec(goodInt);
            string name = Game::instance().getCurPlayer()->getName();
            QString displayName;
            QString displayResc;
            displayResc = displayResc.fromStdString(recType);
            displayName = displayName.fromStdString(name);
            QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!",displayName + " has had an unusually productive cycle. +50 " + displayResc + ".",0,0);
        }
        if(random == 1){
         //retract 50 of a resource
            int badInt = random_int(0,3);
            string recType = LevelManager::instance().downRec(badInt);
            string name = Game::instance().getCurPlayer()->getName();
            QString displayName;
            QString displayRec;
            displayRec = displayRec.fromStdString(recType);
            displayName = displayName.fromStdString(name);
            QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!",displayName + " has just gotten robbed! Oh dear. -50" + displayRec + ".",0,0);
        }
        if(random == 2){
         //remove a structure
          int height = Game::instance().getHeight();
          int width = Game::instance().getWidth();
          int rndWid = random_int(0,width-1);
          int rndHei = random_int(0,height-1);
          bool foo = LevelManager::instance().killStruct(rndHei,rndWid);
          if (foo == true){
          QString ht = ht.fromStdString(to_string(rndHei));
          QString wi = wi.fromStdString(to_string(rndWid));
          QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!","Oh no! A structure has just collapsed at " +  wi + "," + ht +".",0,0);
        }
        }
        if(random == 3){
        //rains fall and flood a square turning it into a river
            int height = Game::instance().getHeight();
            int width = Game::instance().getWidth();
            int rndWid = random_int(0,width-1);
            int rndHei = random_int(0,height-1);
            bool foo = LevelManager::instance().riverSquare(rndHei,rndWid);
            if (foo == true){
            QString ht = ht.fromStdString(to_string(rndHei));
            QString wi = wi.fromStdString(to_string(rndWid));
            QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!","Oh no! Heavy rains have turned the square at " +  wi + "," + ht +" into a river, washing away any progress!.",0,0);
          }
        }
        if(random == 4){
        //a non plain square burns away, leaving a plain
            int height = Game::instance().getHeight();
            int width = Game::instance().getWidth();
            int rndWid = random_int(0,width-1);
            int rndHei = random_int(0,height-1);
            bool foo = LevelManager::instance().burnSquare(rndHei,rndWid);
            if (foo == true){
            QString ht = ht.fromStdString(to_string(rndHei));
            QString wi = wi.fromStdString(to_string(rndWid));
            QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!","Oh no! Flames have burnt " +  wi + "," + ht +" to a crisp! Only some grass remains.",0,0);
        }
        }
        if(random == 5){
        //earthquake turns a square into a canyon
            LevelManager::instance().trader();

        }
        if(random == 6){
            QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Lucky.","Nothing Happened.... this time.",0,0);
        }
        if(random == 7){
            if(Game::instance().getVolc()){

                int height = Game::instance().getHeight();
                int width = Game::instance().getWidth();
                int rndWid = random_int(0,width-1);
                int rndHei = random_int(0,height-1);
                bool foo = LevelManager::instance().eruption(rndHei,rndWid);
                if (foo == true){
                QString ht = ht.fromStdString(to_string(rndHei));
                QString wi = wi.fromStdString(to_string(rndWid));
                QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Random Event!","Oh no! The volcano is erupting and has set " +  wi + "," + ht + "on fire!",0,0);
                Sound::instance().playSound(":/explosionSound",1);
                }
            }
            else{
                QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Lucky.","Nothing Happened.... this time.",0,0);
            }
        }
    else{

    }
}
}



//destory a road or forturess on a square
bool destroyCommand::execute(){
   return true;
}
//load a resource node
bool resourceCommand::execute(){
   return true;
}
//get resources from the node
int resourceCommand::get(){
    return 0;
}
//store resoures in a player's "bank"
int resourceCommand::store(){
    return 0;
}
//begin the dragon's attack
bool dragonCommand::execute(){
    return true;
}
//when a dragon dies, it will be removed,but resources stolen by it are retained
bool dragonCommand::die(){
    return false;
}
//when a dragon takes damage
bool dragonCommand::damage(){
    return true;
}
//takes <newdif> and sets the duff struct accordingly

void Game::setDiff(string newdiff){
    diff = newdiff;
//sets modifiers
    if (diff == "Ez"){
        std::cout << "Easy" << std::endl;
        LevelManager::instance().getDuff()->waterMod = 20;
        LevelManager::instance().getDuff()->goldMod = 5;
        LevelManager::instance().getDuff()->woodMod = 10;
        LevelManager::instance().getDuff()->stoneMod = 7;
        std::cout << "End of easy" << std::endl;

    }
    else if (diff == "Md"){
        LevelManager::instance().getDuff()->waterMod = 15;
        LevelManager::instance().getDuff()->goldMod = 3;
        LevelManager::instance().getDuff()->woodMod = 5;
        LevelManager::instance().getDuff()->stoneMod = 3;
    }
    else {
        LevelManager::instance().getDuff()->waterMod = 10;
        LevelManager::instance().getDuff()->goldMod = 1;
        LevelManager::instance().getDuff()->woodMod = 3;
        LevelManager::instance().getDuff()->stoneMod = 1;
    }
    for (size_t i=0; i<resource_types.size(); i++ ) {
        delete resource_types[i];
    }
    //initialize resources moved to here b/c orignal positon did wierd things with the modifiers
    vector<Resource*> rl;
    rl.push_back(new Resource("water","Wa",LevelManager::instance().getDuff()->waterMod));
    rl.push_back(new Resource("wood","Wo",LevelManager::instance().getDuff()->woodMod));
    rl.push_back(new Resource("stone","St",LevelManager::instance().getDuff()->stoneMod));
    rl.push_back(new Resource("gold","Go",LevelManager::instance().getDuff()->goldMod));
    rl.push_back(new Resource("[none]","",0)); //so resourceType gets can return nempty string and we know what to do with it
    resource_types = rl;

    std::cout << "OK!" << std::endl;

}
Structure *Game::resourceCheck(Player *owner,string type){
    if(type == "Ca"){

       int wood = owner->getWood();
       int stone = owner->getStone();
       if (wood >= 50 && stone >= 300){
           int newwood = (wood-50);
           int newstone = (stone-300);
           owner->setStone(newstone);
           owner->setWood(newwood);
           Structure *br = Game::instance().getStructure("Br");
           return br;
       }
       else{
           return nullptr;
       }
    }
    if(type == "Ri"){
        int wood = owner->getWood();
        int stone = owner->getStone();
        if (wood >= 200 && stone >= 100){
            Structure *bo = Game::instance().getStructure("Bo");
            int newwood = (wood-200);
            int newstone = (stone-100);
            owner->setStone(newstone);
            owner->setWood(newwood);
            return bo;
        }
        else{
            return nullptr;
        }
    }
    if(type == "Mo"){
        int water = owner->getWater();
        int stone = owner->getStone();
        int gold = owner->getGold();
        if (water >= 50 && stone >= 50 && gold >= 100){
            Structure *tu = Game::instance().getStructure("Tu");
            int newwater = (water-50);
            int newstone = (stone-50);
            int newgold = (gold-100);
            owner->setStone(newstone);
            owner->setWater(newwater);
            owner->setGold(newgold);
            return tu;
        }
        else{
            return nullptr;
        }
    }
    if (type == "Fo"){
        int gold = owner->getGold();
        int water = owner->getWater();
        if (water >= 75 && gold >= 100){
            Structure *de = Game::instance().getStructure("De");
            int newwater = (water-75);
            int newgold = (gold-100);
            owner->setWater(newwater);
            owner->setGold(newgold);
            return de;
        }
    }
    if (type == "Sw"){
        int gold = owner->getGold();
        int water = owner->getWater();
        int stone = owner->getStone();
        if (water >= 150 && gold >= 200 && stone >= 200){
          Structure *cl = Game::instance().getStructure("Cl");
          gold -= 200;
          water -= 150;
          stone -= 200;
          owner->setWater(water);
          owner->setGold(gold);
          owner->setStone(stone);
          owner->setSwamped(false);
          return cl;
        }
    }
    if (type == "La"){
        int stone = owner->getStone();
        int water = owner->getWater();
        int wood = owner->getWood();
        if (water >=200 && stone >= 200 && wood >= 200 ){
            Structure *ha = Game::instance().getStructure("Ha");
            wood  -= 200;
            water -= 200;
            stone -= 200;
            owner->setWater(water);
            owner->setWood(wood);
            owner->setStone(stone);
            volcano = false;
            return ha;
        }
    }
    return nullptr;
}

