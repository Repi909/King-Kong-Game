#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

class Display: Plane, Monkey{

    private:
        int level;

    public:

        void hideCursor(){

            HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);            
            CONSOLE_CURSOR_INFO cursorInfo;

            cursorInfo.dwSize =10;
            GetConsoleCursorInfo(out, &cursorInfo);
            cursorInfo.bVisible = false; // set the cursor visibility
            SetConsoleCursorInfo(out, &cursorInfo);
        }

        void move_cursor(int arrayRow, int arrayColumn){
            printf("\033[%d;%d;%dm]", arrayRow, arrayColumn);
        }

        void drawDisplay(){

            //concatenate plane -> projectile grid -> monkey

        }

        int setLevel(int setlevel){
            level = setlevel;
            return level;
        }

        int getLevel(){
            return level;
        }

};

class KBMInput{                                                 //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    private:
        enum action{ UP='w', DOWN ='s', SHOOT = 'e'};           //Enum cases for UP, DOWN, SHOOT
        action Action;

    public:
        void setKBMInput(){                                   //Method to return KBM input when called upon in inherited classes.

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
        }

        action getKBMInput(){
            return Action;
        }
};

class Heading{
    
    private:
        

};

class Projectile{
    private:
        char projArray[21][27];
    
    public:
        int shoot_pProj(){}
        int shoot_mProj(){}
        void projCollision(){}
        void drawProjGrid(){
            //projectile grid draw

        }
};

class Plane: KBMInput{
    protected:
        int planeArray[15][27];
    
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

        void drawPlane(){

        }

        void planeMove(){
            if(getKBMInput() != SHOOT){
                if(getKBMInput()== UP){
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
        char monkeyArray[24][27];
        string monkey = R"( || (__/ ||
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
                            ||      ||          )";

    public:

        char * createMonkey(char mArray[24][22], string monkey){
            for(int i=0; i<sizeof(mArray); i++)
            strncpy(mArray[i], monkey.c_str(), sizeof(mArray));
            return *mArray;
        }

        void setMonkeyHitPoints(int hp){
            hp= hitPoints;
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