#include "gamemodel.h"
#include <string>
#include <iostream>
#include <istream>

using namespace std;

Game *Game::instance_ = NULL;

//used for construction of bridges/roads
bool buildCommand::execute(){
    return true;
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

Game& Game::instance() {
    if (instance_ == NULL ) {
        instance_ = new Game();
    }
    return *instance_;
}

void Game::setGameLoader(GameFileManager *gfm) {
    loader = gfm;
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
