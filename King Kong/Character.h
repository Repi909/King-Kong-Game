#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include "Setup.h"
#include "Projectile.h"

class Character : public Setup, public Projectile {

private:
    int hitPoints;
    int currentY_pos;

public:
    Character(int hp);
    Character();
    void setHitPoints(int hp);
    int getHitPoints();
    void setCurrentYPos(int yPos);
    int getCurrentYPos();
};

#endif