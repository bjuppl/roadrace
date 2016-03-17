#include "player.h"

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
