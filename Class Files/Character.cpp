#include ".\Header Files\Character.h"

//default constructor
//names {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"}
Character::Character(){
    name = "Amelia Earhart";
    hitPoints = 10;
    ammoCount = 5;
    planeArt;
}

//set method for hit points.
void Character::SetHitPoints(int _hitPoints){
    hitPoints = _hitPoints;
}

//get method for hit points.
int Character::GetHitPoints(){
    return(hitPoints);
}

int Character::GetAmmoCount(){
    return(ammoCount);
}

void Character::SetAmmoCount(int _ammoCount){
    ammoCount = _ammoCount;
}