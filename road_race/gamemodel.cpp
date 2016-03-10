#include "gamemodel.h"
#include <string>
#include <iostream>
#include <istream>
using namespace std;
bool buildCommand::execute(){
    return true;
}
bool game::save(){
    return true;
}
string game::load(){
    return "string";
}
void game::update(){

}
bool destroyCommand::execute(){
   return true;
}
bool resourceCommand::execute(){
   return true;
}
int resourceCommand::get(){
    return 0;
}
int resourceCommand::store(){
    return 0;
}
bool dragonCommand::execute(){
    return true;
}
bool dragonCommand::die(){
    return false;
}
bool dragonCommand::damage(){
    return true;
}
