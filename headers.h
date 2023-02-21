#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

class Setup{

    public:

    char* stringToArray(int arrayRow, int arrayCol, std::string conversion){

        char fullArray[arrayRow][arrayCol];
        for (int row = 0; row < sizeof(arrayRow); row++){
            for(int col = 0; col < sizeof(arrayCol); col++){
                fullArray[row][col] = conversion[col + (row * 9)];
            } 
        }
        return *fullArray;
    }
};


class KBMInput{                                                 //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    protected:
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

class Heading: public Setup {
    
    private:
        char headingArrayRow[5];
        char headingArrayCol[59];
        std::string headingASCII = R"( _  ___               _  __                    ____                      
                                      | |/ (_)_ __   __ _  | |/ /___  _ __   __ _   / ___| __ _ _ __ ___   ___ 
                                      | ' /| | '_ \ / _` | | ' // _ \| '_ \ / _` | | |  _ / _` | '_ ` _ \ / _ \
                                      | . \| | | | | (_| | | . | (_) | | | | (_| | | |_| | (_| | | | | | |  __/
                                      |_|\_|_|_| |_|\__, | |_|\_\___/|_| |_|\__, |  \____|\__,_|_| |_| |_|\___|
                                                    |___/                   |___/                              )";

    public:
        // char headingArray[5][59];

        void drawHeadingArray(){
            char* arrptr = stringToArray(5,59,headingASCII);
            for(int i=0;i<sizeof(headingArrayRow);i++){
                for(int j=0;i<sizeof(headingArrayCol);i++)
                std::cout << arrptr[i];
            }
        }
};

class Projectile{
    private:
        char projArray[20][27];
    
    public:
        int shoot_pProj(){
            return 0;
        }
        int shoot_mProj(){
            return 0;
        }
        void projCollision(){}
        void drawProjGrid(){
            //projectile grid draw

        }
};

class Plane: public KBMInput{
    protected:
        char planeArray[15][27];
    
    public:

        void drawPlane(){

        }

        void planeMove(){
            if(getKBMInput() != SHOOT){
                if(getKBMInput()== UP){
                }
                else{
                }
            }
        }
};

class Monkey: public Setup{
    private:
        int hitPoints;
        char monkeyArray[24][27];
        std::string monkey = R"( || (__/ ||
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

        void drawMonkeyArray(){
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

class Display: public Heading, public Plane, public Monkey {

    private:
        int level;
        bool Enable;

    public:

        void show_cursor (bool Enable){
          if (Enable) printf ("\033[?25h");
          else printf ("\033[?25l");
        } // show_cursor taken from Test.cpp written by Peter Jones

        void move_cursor(int arrayRow, int arrayColumn){
            printf("\033[%d;%d;%dm]", arrayRow, arrayColumn);
        } // move_cursor taken from Test.cpp written by Peter Jones

        void drawDisplay(){
            show_cursor(Enable);
            move_cursor(0,0);
            drawHeadingArray();
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

#endif