#include "Character.h"

//object constructor
Character::Character(int hp) {
    hitPoints = hp;
    currentY_pos = 15;
}

//default constructor
Character::Character(){
    hitPoints = 20;
    currentY_pos = 15;
}

//set method for hit points.
void Character::setHitPoints(int hp){
    hitPoints= hp;
}

//get method for hit points.
int Character::getHitPoints(){
    return(hitPoints);
}

//set method for current YPos
void Character::setCurrentYPos(int yPos){
    currentY_pos = yPos;
}

//get method for current YPos
int Character::getCurrentYPos(){
    return currentY_pos;
}