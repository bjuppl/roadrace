#include "player.h"
#include "gamemodel.h"
#include "levelmanager.h"

void Player::setResource(string type, int amt) {
    if ( type == "Go") {
        goldCount = amt;
    } else if ( type == "Wa" ) {
        waterCount = amt;
    } else if ( type == "Wo" ) {
        woodCount = amt;
    } else if (type == "St") {
        stoneCount = amt;
    }
}

void Player::incResource(string type, int amt) {
   if(swamped == false){
       if ( type == "Go") {
        goldCount += amt;
    } else if ( type == "Wa" ) {
        waterCount += amt;
    } else if ( type == "Wo" ) {
        woodCount += amt;
    } else if (type == "St") {
        stoneCount += amt;
    }
   }
   else{
       if ( type == "Go") {
               goldCount += (amt/2);
           } else if ( type == "Wa" ) {
               waterCount += (amt/2);
           } else if ( type == "Wo" ) {
               woodCount += (amt/2);
           } else if (type == "St") {
               stoneCount += (amt/2);
           }
}
   if(Game::instance().getVx() != 444 && Game::instance().getVy() != 444){
   if(Game::instance().getSquare(Game::instance().getVx(),Game::instance().getVy())->getBurn()){
       string badamt = LevelManager::instance().getBurn();
       if (badamt == "Wa" && waterCount >= 30){
           waterCount -= 30;
       }
       else if (badamt == "Go" && goldCount >= 30){
           goldCount -= 30;
       }
       else if (badamt == "St" && stoneCount >= 30){
          stoneCount -= 30;
       }
       else if (badamt == "Wo" && woodCount >= 30){
          woodCount -= 30;
       }
   }
   }
}
int Player::getResource(string type) {
    if ( type == "Go") {
        return goldCount;
    } else if ( type == "Wa" ) {
        return waterCount;
    } else if ( type == "Wo" ) {
        return woodCount;
    } else if (type == "St") {
        return stoneCount;
    }
    return 0;

}
