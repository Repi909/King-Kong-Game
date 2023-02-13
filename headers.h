#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string.h>
#include <conio.h>

class KBMInput{                                                 //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    protected:
        enum action{ UP='w', DOWN ='s', SHOOT = 'e'};           //Enum cases for UP, DOWN, SHOOT
        action Action;



    public:

        action setKBMInput(){                                   //Method to return KBM input when called upon in inherited classes.

            char input = getch();
            if(input == 'w'){
                Action = UP;
            }
            else if(input == 's'){
                Action = DOWN;
            }
            else if(input == 'e'){
                Action = SHOOT;
            }
            return Action;
        }
};

class Display: public Projectile, Monkey{
    private:
        int yPos[15];
        int xPos[20];
    
    public:
        void setup(){
            setMonkeyHitPoints(100);
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
        std::cout << "Monkey HP:" << getMonkeyHitPoints() << endl;
        }

    void projDisplay(){}

        
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

class Plane: KBMInput{
    protected:
        int pPos_y[15];
    
    public:
        int pPos = 8;
        int* get_pPos(int pPos){
            // for(int i=0;i<sizeof(pPos_y);i++){
            //     if(pPos_y[i]== 1){
            //         pPos = i;
            //     }
            pPos_y[pPos] = 1;
            return pPos_y ;
        }

        void planeMove(){
            if(setKBMInput() != SHOOT){
                if(setKBMInput()== UP){
                    pPos++;
                }
                else{
                    pPos--;
                }
            }
        }

};

class Monkey{
    private:
        int hitPoints;
    
    public:

        void setMonkeyHitPoints(int hp){
            hp=hitPoints;
        }

        int getMonkeyHitPoints(){
            return(hitPoints);
        }

        int monkeyHit(int hitPoints, int pProj_x[]){
            if(pProj_x[20]==1){
                hitPoints--;
            }
            return hitPoints;
        }
};

#endif