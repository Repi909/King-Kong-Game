#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
class Character{

    private:
        std::string name;
        int hitPoints;
        int ammoCount;

        //TODO- Find better/easier way of displaying plane. Container?
        const char planeArt[68] = R"(      __|__
                                    --@--@--(_)--@--@--)";

    public:
        Character();
        int GetHitPoints();
        void SetHitPoints(int _hitPoints);
        int GetAmmoCount();
        void SetAmmoCount(int _ammoCount);
};

#endif