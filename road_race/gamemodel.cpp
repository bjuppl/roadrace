#include <string>
#include <iostream>
#include <istream>

#include "gamemodel.h"
#include "player.h"

using namespace std;

class Player;

Game *Game::instance_ = NULL;
Updater *Updater::instance_ = NULL;

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


Updater& Updater::instance() {
    if (instance_ == NULL ) {
        instance_ = new Updater();
    }
    return *instance_;
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

void Game::setSquares ( vector<vector<Square*>> sq ) {
    for ( size_t i=0; i<squares.size(); i++ ) {
        for (size_t j=0; j<squares.at(i).size(); j++ ) {
            delete squares[i][j];
        }
    }
    squares = sq;
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
