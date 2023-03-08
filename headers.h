#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

  class Setup{

    public:
        bool Enable;
        int level = 1;
        
        // show_cursor taken from Test.cpp written by Peter Jones
        void show_cursor (bool Enable){
            if (Enable) printf ("\033[?25h");
            else printf ("\033[?25l");
        }

        //Method to change a string into an array of chars or 'cstring'.
        char* create_cstring(std::string asciiArt){

            char* cstring = new char[asciiArt.length() + 1];
            cstring[asciiArt.length()] = '\0';
            for(int i = 0; i< asciiArt.length();i++){
                cstring[i] = asciiArt[i];
            }
            // char* cstring = asciiArt.c_str();  headingASCII = 6 rows 73 columns. monkeyArt = 24 rows 24 columns 
            return cstring;
        }
        
        // print_at adapted from Test.cpp written by Peter Jones
        void print_at (int arrayRow, int arrayCol, int length, std::string conversion){
            
            char* cstring = create_cstring(conversion);
            //for(int i=0; i<sizeof(arrayRow); i++){
                for(int j=0; j<length; j++){
                    std::cout << cstring[j];
                }
            //}
           
        }
        //set and get methods.
        int setLevel(int setlevel){
            level = setlevel;
            return level;
        }

        int getLevel(){
            return level;
        }

  };


class KBMInput{ //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.

    protected:
        enum action{ UP='w', DOWN ='s', SHOOT = 3, NONE = 'z'};     //Enum cases for UP, DOWN, SHOOT to avoid char errors.
        action Action;

    public:

        //Methods to set and get KBM Input.  
        void setKBMInput(char input){
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
        int projectileNum;      //number of projectiles fired at one instance.
        int projectileFrq;      //frequency at which projectiles are fired by Monkey.
        //char projArray[20][27];
    
    public:
        char projectile;

        //constructor for Projectile class to allocate projectile char.
        Projectile(char Projectile){
            projectile = Projectile;
        }

        //default constructor
        Projectile() = default;

        //Get and set methods for projectile frequency and number of projectiles.
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

        //Method to find position of projectile within array. If projectiles are next to each other, moveProjectile will delete from array.
        void projCollision(){
            

        }

        //find position of projectile within array. Increment the projectile to the left or right depending on monkey or plane.
        void moveProjectiles(){
            CHAR_INFO ci;
            short i;
            short j;
            COORD xy = {i, j};
            SMALL_RECT region = {15, 7, 230, 25};
            for(i=6; i<30;i++){
                for(j=21; j<226;i++){

                    //uses ReadConsoleOutput from windows.h to return a zero or nonzero if there is a proj in output.
                    int returnval = ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, {205,24}, xy, &region);
                    if(returnval == 0){
                        
                    }
                }
            }
        }
};

class Character: public KBMInput, public Setup, public Projectile{

    private:
        int loopCounter;
        int hitPoints;
        int currentY_pos;
        int RandIndex = rand() % 6;
        std::string pname;
        std::string mname;
        const char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
        const char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};

        void setCharacterName(){
            pname = monkeyName[RandIndex];
            mname = monkeyName[RandIndex];
        }

    public:

        //object constructor for Character class with default defined below.
        Character(int hp){
            hitPoints = hp;
        }

        //default constructor.
        Character()=default;

        //get and set methods for hit points.
        void setHitPoints(int hp){
            hitPoints= hp;
        }

        int getHitPoints(){
            return(hitPoints);
        }

        int setCurrentYPos(int yPos){
            currentY_pos = yPos;
        }

        int getCurrentYPos(){
            return currentY_pos;
        }

        void shootMonkeyProj(){

            int currentProjNum = getProjectileNum();
            if(loopCounter>getProjectileFrq()){
                for(int i = 0; i<currentProjNum; i++){
                    int projRow = rand()% 24 + 6;   //might be bug where print on same line twice.
                    print_at(projRow, 226, 1, &projectile); //226 is furthest right column before monkey art
                }
            }
        }
};

class Display: public Character {

    private:
        bool stop = false;
        int displayColumns;
        int displayRows;
        std::string levelIndicator = "Level: " + level;
        std::string monkeyHPIndicator = "Monkey HP: ";
        std::string planeHPIndicator = "Lives: ";
        std::string headingASCII = " _  ___               _  __                    ____                      \n| |/ /_ _ __   __ _  | |/ /___  _ __   __ _   / ___| __ _ _ __ ___   ___ \n| ' /| | '_ \\ / _` | | ' // _ \\| '_ \\ / _` | | |  _ / _` | '_ ` _ \\ / _ \\ \n| . \\| | | | | (_| | | . | (_) | | | | (_| | | |_| | (_| | | | | | |  __/\n|_|\\_|_|_| |_|\\__, | |_|\\_\\___/|_| |_|\\__, |  \\____|\\__,_|_| |_| |_|\\___|\n              |___/                   |___/                              ";
        std::string planeArt = " -      ___    \n/ \\__,°_/_/__| \n'/-___ /_/___])\n          '° | ";
        std::string monkeyArt = " || (__/ ||\n||  | | :-'''-.\n||==| \\/-=-.   \\ \n||  |(_|o o/   |_\n||   \\/ '  \\   ,_)\n||====\\ ^  /__/\n||     ;--'  `-.||    /      .  \\\n||===;        \\  \\\n    ||   |         | |\n    || .-\\ '     _/_/\n    |:'  _;.    (_  \\\n    /  .'  `;\\   \\_/\n   |_ /     |||  |\\\\\n  /  _)=====|||  | ||\n /  /|      ||/  / //\n \\_/||      ( `-/ ||\n    ||======/  /  \\ .-.\njgs ||      \\_/    \'-'/\n    ||      ||      `'`\n    ||======||\n    ||      ||          ";
        std::string endGameAscii = "";

    public:

        Display(int columns, int rows){ //250 columns // 30 rows
            displayColumns=columns;
            displayRows=rows;
        }

        //method to form cstrings into display format planned and print at correct place in array.
        void drawDisplay(){
            
            print_at(0,0,7,planeHPIndicator);
            print_at(0, 89, 150, headingASCII);
            print_at(0,235,15,levelIndicator);
            print_at(3,235,15,monkeyHPIndicator);
            print_at(15,15,60,planeArt);
            print_at(6,226,300,monkeyArt);

        }

        //method to move plane object up and down array based on KBM input.
        void moveCharacter(){
            char input = getch();   //stores the value entered by user in input variable
            setKBMInput(input);
            if(getKBMInput() == SHOOT){
                
                
            }

            else if(getKBMInput()== UP){
                int Ypos = getCurrentYPos();    //gets current Y position of the AsciiArt and increments or decrements based on keyboard input.
                Ypos++;
                setCurrentYPos(Ypos);
                print_at(Ypos,0,15,planeArt);
            }

            else if(getKBMInput() == DOWN){
                int Ypos = getCurrentYPos();
                Ypos--;
                setCurrentYPos(Ypos);
                print_at(Ypos,0,15,planeArt);
            }
        }

        void nextLevel(){
            int currentLevel = getLevel();
            currentLevel++;
            setLevel(currentLevel);
            int currentHP = getHitPoints();
            setHitPoints(currentHP + 2);
        }

        bool endGame(){

            int stopRun;
            print_at(15,125,125,endGameAscii);
            //print_at(print in the middle of the array);
            std::cout << "Press Enter to end game.";
            std::cin >> stopRun;
            if(stopRun == 10){
                stop = true;
            }
            return stop;
        }

};

#endif