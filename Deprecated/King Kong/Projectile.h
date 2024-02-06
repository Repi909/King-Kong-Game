#pragma once

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

class Projectile {
private:
    int projectileNum = 1;
    int projectileFrq = 5000;

public:
    Projectile();
    std::string mProjectile = ")";
    int getProjectileFrq();
    int getProjectileNum();
    void setProjectileNum(int pNum);
    void setProjectileFrq(int pFrq);
    int randProjRow();
    void projCollision();
    std::vector<std::vector<COORD>> getPlaneProjectilePositions(COORD projectileTopLeft, int projectileRegion[], std::string projectile);
};

#endif