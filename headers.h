#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

  class Setup{

    public:
        bool Enable;
        int level = 1;

        void show_cursor (bool Enable){
            if (Enable) printf ("\033[?25h");
            else printf ("\033[?25l");
        } // show_cursor taken from Test.cpp written by Peter Jones

        void print_at (int Row, int Col, char* array[][]){
            
            for(int i=0; i<sizeof(array); i++){
                for(int j=0; j<sizeof(array); j++){
                    wprintf (L"\033[%d;%df%lc", Row, Col, array[i]); // print the Unicode character
                }
            }
           
        }// print_at taken and adapted from Test.cpp written by Peter Jones

        int setLevel(int setlevel){
            level = setlevel;
            return level;
        }

        int getLevel(){
            return level;
        }

        void nextLevel(){
            int currentLevel = getLevel();
            currentLevel++;
            setLevel(currentLevel);
            int currentHP = getHitPoints();
            setHitPoints(currentHP + 2);
        }
  };


class KBMInput{                                                 //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    protected:
        enum action{ UP='w', DOWN ='s', SHOOT = 3, NONE = 'z'};           //Enum cases for UP, DOWN, SHOOT
        action Action;

    public:
        void setKBMInput(char input){                                   //Method to return KBM input when called upon in inherited classes.

            if(input == 'w'){
                Action = UP;
            }
            else if(input == 's'){
                Action = DOWN;
            }
            else if(input == 3){
                Action = SHOOT;
            }
            else{
                Action = NONE;
            }
        }

        action getKBMInput(){
            return Action;
        }
};

class Projectile{
    private:
        int projectileNum;
        int projectileFrq;
        //char projArray[20][27];
    
    public:

        int getProjectileFrq(){
            return projectileFrq;
        }

        int getProjectileNum(){
            return projectileNum;
        }

        void setProjectileNum(int pNum){
            projectileNum = pNum;
        }

        void setProjectileFrq(int pFrq){
            projectileFrq = pFrq;
        }

        void projCollision(){

        }

        void drawProjGrid(){
            //projectile grid draw

        }
};

class Character: public KBMInput, public Setup, public Projectile{

    private:
        int loopCounter;
        int hitPoints;
        char projectile;
        int RandIndex = rand() % 6;
        std::string pname;
        std::string mname;
        char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
        char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};

        void setCharacterName(){
            pname = monkeyName[RandIndex];
            mname = monkeyName[RandIndex];
        }


    public:

        Character(int hp, char proj){       //object constructor for Character class with default defined below.
            hitPoints = hp;
            projectile = proj;
        }

        Character()=default;

        void setHitPoints(int hp){
            hitPoints= hp;
        }

        int getHitPoints(){
            return(hitPoints);
        }

        void moveCharacter(){
            char input = getch();
            setKBMInput(input);
            if(getKBMInput() == SHOOT){
            }

            else if(getKBMInput()== UP){

            }

            else if(getKBMInput() == DOWN){

            }
        }

        void shootMonkeyProj(){

            if(loopCounter>getProjectileFrq())
            int currentProjNum = getProjectileNum();
            for(int i = 0; i<currentProjNum(); i++){
                int projRow = rand()% 24 + 6;   //might be bug where print on same line twice.
                move_cursor(projRow);
                printf(projectile);
            }
        }
};

class Display: public Setup, public Character {

    private:
        int displayColumns;
        int displayRows;
        std::string levelIndicator = "Level: ";
        std::string monkeyHPIndicator = "Monkey Health: ";
        std::string planeHPIndicator = "Lives: "
        std::string headingASCII = " _  ___               _  __                    ____                      \n| |/ /_ _ __   __ _  | |/ /___  _ __   __ _   / ___| __ _ _ __ ___   ___ \n| ' /| | '_ \\ / _` | | ' // _ \\| '_ \\ / _` | | |  _ / _` | '_ ` _ \\ / _ \\ \n| . \\| | | | | (_| | | . | (_) | | | | (_| | | |_| | (_| | | | | | |  __/\n|_|\\_|_|_| |_|\\__, | |_|\\_\\___/|_| |_|\\__, |  \\____|\\__,_|_| |_| |_|\\___|\n              |___/                   |___/                              ";
        std::string planeArt = "";
        std::string monkeyArt = " || (__/ ||\n||  | | :-'''-.\n||==| \\/-=-.   \\ \n||  |(_|o o/   |_\n||   \\/ '  \\   ,_)\n||====\\ ^  /__/\n||     ;--'  `-.||    /      .  \\\n||===;        \\  \\\n    ||   |         | |\n    || .-\\ '     _/_/\n    |:'  _;.    (_  \\\n    /  .'  `;\\   \\_/\n   |_ /     |||  |\\\\\n  /  _)=====|||  | ||\n /  /|      ||/  / //\n \\_/||      ( `-/ ||\n    ||======/  /  \\ .-.\njgs ||      \\_/    \'-'/\n    ||      ||      `'`\n    ||======||\n    ||      ||          ";
        std::string endGame = ""

        const char* create_cstring(std::string asciiArt){
            const char* cstring = asciiArt.c_str();  //headingASCII = 6 rows 73 columns. monkeyArt = 24 rows 24 columns 
            return cstring;
        }

    public:

        Display(int columns, int rows){ //250 columns // 30 rows
            displayColumns=columns;
            displayRows=rows;
            bool stop = false;
        }

        void drawDisplay(){
            char* heading = create_cstring(headingASCII);
            print_at(0, 0, heading)
            char* levelInd = create_cstring(levelIndicator);
            print_at(levelInd)
            char* monkeyHP = create_cstring(monkeyHPIndicator);
            print_at(monkeyHP)
            char* plane = create_cstring(planeArt);
            print_at(plane)
            char* monkey = create_cstring(monkeyArt);
            print_at(monkey)


            //form cstrings into display format planned

        }

        bool endGame(){

            create_cstring(endGame);
            //print_at(print in the middle of the array);
            cout << "Press Enter to end game."
            cin << int endGame;
            if(endGame == 10){
                stop = true;
            }
            return stop;
        }

};

#endif