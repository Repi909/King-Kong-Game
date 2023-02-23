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

        void move_cursor(int arrayRow, int arrayColumn){
            printf("\033[%d;%d;%dm]", arrayRow, arrayColumn);
        } // move_cursor taken from Test.cpp written by Peter Jones

        int setLevel(int setlevel){
            level = setlevel;
            return level;
        }

        int getLevel(){
            return level;
        }
  };


class KBMInput{                                                 //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    protected:
        enum action{ UP='w', DOWN ='s', SHOOT = 3, NONE = 'z'};           //Enum cases for UP, DOWN, SHOOT
        action Action;

    public:
        void setKBMInput(char input = getch()){                                   //Method to return KBM input when called upon in inherited classes.

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
        //char projArray[20][27];
    
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

class Character: public KBMInput{

    private:
        int hitPoints;
        char projectile;
        int RandIndex = rand() % 6;
        std::string pname;
        std::string mname;
        char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
        char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};

    public:

        Character(int hp, char proj){
            hitPoints = hp;
            projectile = proj;
        }

        void setCharacterName(){
            pname = monkeyName[RandIndex];
            mname = monkeyName[RandIndex];
        }

        void setHitPoints(int hp){
            hitPoints= hp;
        }

        int getHitPoints(){
            return(hitPoints);
        }

        void moveCharacter(){
            setKBMInput(getch());
            if(getKBMInput() == SHOOT){
            }

            else if(getKBMInput()== UP){

            }

            else if(getKBMInput() == DOWN){

            }

            else{

            }
        }
};

class Display: public Setup, public Character {

    private:
        std::string levelIndicator = "Level: ";
        std::string monkeyHPIndicator = "Monkey Health: ";
        std::string headingASCII = " _  ___               _  __                    ____                      \n| |/  /_ _ __   __ _  | |/ /___  _ __   __ _   / ___| __ _ _ __ ___   ___ \n| ' /| | '_ \\ / _` | | ' // _ \\| '_ \\ / _` | | |  _ / _` | '_ ` _ \\ / _ \\ \n| . \\| | | | | (_| | | . | (_) | | | | (_| | | |_| | (_| | | | | | |  __/\n|_|\\_|_|_| |_|\\__, | |_|\\_\\___/|_| |_|\\__, |  \\____|\\__,_|_| |_| |_|\\___|\n              |___/                   |___/                              ";
        std::string planeArt = "";
        std::string monkeyArt = " || (__/ ||\n||  | | :-'''-.\n||==| \\/-=-.   \\ \n||  |(_|o o/   |_\n||   \\/ '  \\   ,_)\n||====\\ ^  /__/\n||     ;--'  `-.||    /      .  \\\n||===;        \\  \\\n    ||   |         | |\n    || .-\\ '     _/_/\n    |:'  _;.    (_  \\\n    /  .'  `;\\   \\_/\n   |_ /     |||  |\\\\\n  /  _)=====|||  | ||\n /  /|      ||/  / //\n \\_/||      ( `-/ ||\n    ||======/  /  \\ .-.\njgs ||      \\_/    \'-'/\n    ||      ||      `'`\n    ||======||\n    ||      ||          ";

        const char* create_cstring(std::string asciiArt){
            const char* cstring = asciiArt.c_str();  //headingArr = 6 rows 73 columns
            return cstring;
        }

    public:

        Display(int columns, int rows){ //250 columns // 30 rows



        }

        void drawDisplay(){
            create_cstring(headingASCII);
            create_cstring(levelIndicator);
            create_cstring(monkeyHPIndicator);
            create_cstring(planeArt);
            create_cstring(monkeyArt);

            //form cstrings into display format planned

        }

};

#endif