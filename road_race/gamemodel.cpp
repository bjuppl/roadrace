#include <string>
#include <iostream>
#include <istream>

#include "gamemodel.h"
#include "gui.h"
#include "player.h"
#include "square.h"
#include "levelmanager.h"
using namespace std;

class Player;

Game *Game::instance_ = NULL;
Updater *Updater::instance_ = NULL;

Game::Game() {
    vector<Resource*> rl;
    rl.push_back(new Resource("water","Wa",10));
    rl.push_back(new Resource("wood","Wo",3));
    rl.push_back(new Resource("stone","St",1));
    rl.push_back(new Resource("gold","Go",1));
    rl.push_back(new Resource("[none]","No",0)); //so resourceType gets can return "No" and we know what to do with it
    rl.push_back(new Resource("[none]","",0)); //so resourceType gets can return nempty string and we know what to do with it
    resource_types = rl;

    vector<Structure*> sl;
    //Bo = boat, Br = bridge, Wa = wall, Tu = tunnel
    vector<Price> a = {Price("Wo",100),Price("St",50)};
    sl.push_back(new Structure("boat","Bo",a));
    vector<Price> b = {Price("Wo",200),Price("St",100)};
    sl.push_back(new Structure("bridge","Br",b));
    vector<Price> c = {Price("Wo",50),Price("St",300)};
    sl.push_back(new Structure("wall","wa",c));
    vector<Price> d = {Price("Wa",50),Price("Go",100),Price("St",50)};
    sl.push_back(new Structure("tunnel","Tu",d));

    structure_types = sl;

}

void Game::start(){
    Updater::instance().start();

}

void Game::updateResources() {

    for ( size_t i=0; i<player_list.size(); i++ ) {
        vector<Square*> mysquares;
        Player *p = player_list[i];
        mysquares = getPlayerSquares(p);
        for ( size_t j=0; j<mysquares.size(); j++ ) {
            if(mysquares.at(j)->getType() != "Wi")
            {
                std::string rtype = mysquares.at(j)->getResourceType();
                int add = getResource(rtype)->value;

                p->incResource(rtype, add);
            }
        }
    }


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
}

void Updater::stop() {
    timer->stop();
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
    delete gfm;
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
        LevelManager::instance().getDuff()->stoneMod = 5;
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
