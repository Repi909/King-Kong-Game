#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string.h>

class KBMInput: public Projectile, Plane{
    private:
        enum action{ UP='w', DOWN ='s', SHOOT = 'e'};

    public:
        void planeAction(enum action){
            if(action == UP){
                if(get_pPos() == 15){
                    Plane::pPos;
                }
                Plane::pPos++;
            }
            else if(action == DOWN){
                if(get_pPos() == 0){
                    Plane::pPos;
                }
                Plane::pPos--;
            }
            else if(action == SHOOT){
                Plane::get_pPos();
                Projectile::shoot_pProj()
            }
        }
};

class Display{
    private:
        int yPos[15];
        int xPos[20];
    
    public:
        void setup(){
            for(int i=0;i<sizeof(yPos); i++){
                for(int j = 0; j<sizeof(xPos); j++){
                    std::cout << '/t';
                }
            }
            /*
            std::cout << R"(    || __   ||
    ||=\_`\=||
    || (__/ ||
    ||  | | :-"""-.
    ||==| \/-=-.   \
    ||  |(_|o o/   |_
    ||   \/ "  \   ,_)
    ||====\ ^  /__/
    ||     ;--'  `-.
    ||    /      .  \
    ||===;        \  \
    ||   |         | |
    || .-\ '     _/_/
    |:'  _;.    (_  \
    /  .'  `;\   \\_/
   |_ /     |||  |\\
  /  _)=====|||  | ||
 /  /|      ||/  / //
 \_/||      ( `-/ ||
    ||======/  /  \\ .-.
jgs ||      \_/    \'-'/
    ||      ||      `"`
    ||======||
    ||      ||) << '/n';
            */
        }
        
};

class Projectile{
    private:
        int pProj_y[15];
        int pProj_x[20];
        int mProj_y[15];
        int mProj_x[20];
    
    public:
        int shoot_pProj(int pPos){}
        int shoot_mProj(){}
        void projCollision(){}

};

class Plane{
    protected:
        int pPos_y[15];
    
    public:
        int pPos;
        int get_pPos(){
            for(int i=0;i<sizeof(pPos_y);i++){
                if(pPos_y[i]== 1){
                    pPos = i;
                }
            }            
            return pPos;
        }

};

class Monkey{
    private:
        int hitPoints;
    
    public:
        int monkeyHit(int hitPoints, int pProj_x[]){
            if(pProj_x[20]==1){
                hitPoints--;
            }
            return hitPoints;
        }
};

#endif