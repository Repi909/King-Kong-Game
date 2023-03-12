#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <sstream>
#include <vector>

class Setup{

    public:
        bool Enable;
        int level = 1;
        COORD coord;    //define new class for console coords from windows.h
        
        // show_cursor taken from Test.cpp written by Peter Jones
        void show_cursor (bool Enable){
            if (Enable) printf ("\033[?25h");
            else printf ("\033[?25l");
        }

        //Method to change a string into a 2D array.
        std::vector<std::vector<char>> create_array_from_string(const std::string& asciiArt) {
            std::vector<std::vector<char>> array;
            std::stringstream stringconvert(asciiArt);
            std::string line;
            while (getline(stringconvert, line)) {
                std::vector<char> char_line;
                for (char c : line) {
                    char_line.push_back(c);
                }
                array.push_back(char_line);
            }
            return array;
        }

        // print_at adapted from Test.cpp written by Peter Jones
        void print_at (int x, int y, std::string String){
            
            coord.X = x;    //define x coord
            coord.Y = y;    //define y coord
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //set cursor position using defined coords
            std::cout << String;
        }

        //overloaded print_at function to take value for string array.
        void print_at (int x, int y, const std::vector<std::vector<char>>& array){
        
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            for (int i = 0; i < array.size(); i++) {            //nested for loop to print string array and then increment coord to print on next line.
                for (int j = 0; j < array[i].size(); j++) {
                    std::cout << array[i][j];
                }
                coord.X = x;
                coord.Y = y++;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            }
        }
        
        //overloaded print_at function to take value for number.
        void print_at (int arrayRow, int arrayCol, int number){

            coord.X = arrayRow;
            coord.Y = arrayCol;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << number;
        }

        //set method for level
        int setLevel(int setlevel){
            level = setlevel;
            return level;
        }

        //get method for level
        int getLevel(){
            return level;
        }

};


class KBM { //Unbuffered keyboard input from conio.h using the getch() method. Enumerated values for referencing later in code.
        
    public:

        char input;

        char KBMInput(DWORD startTime){
            
            DWORD currentTime = GetTickCount();
            DWORD elapsedTime = currentTime - startTime;
            while(1){

                if (_kbhit()){ // Check if a key has been pressed
                    input = getch(); // Read the character
                    break;
                }

                if (elapsedTime > 500){
                    input = 'p'; // Timeout occurred
                    break;
                }
            }
            return input;
        }
};

class Projectile{
    private:
        int projectileNum = 1;      //number of projectiles fired at one instance.
        int projectileFrq = 5000;      //frequency at which projectiles are fired by Monkey in seconds.
    
    public:
        std::string mProjectile = ")";

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

        int randProjRow(){
            int projRow = rand() % 22 + 8;
            return projRow;
        }

        //Method to find position of projectile within array. If projectiles are next to each other, moveProjectile will delete from array.
        void projCollision(){
            

        }

        std::vector<int> getPlaneProjectilePositions(COORD projectileTopLeft, int projectileRegion[], std::string projectile) {
            HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            GetConsoleScreenBufferInfo(console, &consoleInfo);
            COORD foundPos = {-1, -1};
            for (short int i = projectileTopLeft.X; i < projectileTopLeft.X + projectileRegion[0]; i++) {
                for (short int j = projectileTopLeft.Y; j < projectileTopLeft.Y + projectileRegion[1]; j++) {
                    COORD projPos = {i, j};
                    SetConsoleCursorPosition(console, projPos);
                    CHAR_INFO projChar;
                    SMALL_RECT readRegion = {projPos.X, projPos.Y, projPos.X, projPos.Y};
                    if (ReadConsoleOutput(console, &projChar, {1, 1}, {0, 0}, &readRegion) && projChar.Char.AsciiChar == '-') {
                        foundPos = projPos;
                        break;
                    }
                }
                if (foundPos.X != -1 && foundPos.Y != -1) {
                    break;
                }
            }
            return {foundPos.X, foundPos.Y};
        }
};

class Character: public Setup, public Projectile{

    private:
        int hitPoints;
        int currentY_pos;

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
};

class Display: public Character, public KBM {

    private:
        COORD projectileTopLeft = {20,8};
        int projectileRegion[2] = {82,22};

        int counter = 0;
        int projRow;

        int RandIndex = rand() % 6;
        std::string pname;
        std::string mname;
        //const char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
        //const char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};
        
        bool stop = false;
        int x;
        int y;
        const std::string planeProjectile = "-";
        const std::string levelIndicator = "Level: ";
        const std::string monkeyHPIndicator = "Monkey HP: ";
        const std::string planeHPIndicator = "Lives: X X X";
        const std::string headingASCII = R"(
 _  _______ _   _  _____   _   _____  _   _  _____    _____          __  __ ______ 
| |/ /_   _| \ | |/ ____| | |/ / __ \| \ | |/ ____|  / ____|   /\   |  \/  |  ____|
| ' /  | | |  \| | |  __  | ' / |  | |  \| | |  __  | |  __   /  \  | \  / | |__   
|  <   | | | . ` | | |_ | |  <| |  | | . ` | | |_ | | | |_ | / /\ \ | |\/| |  __|  
| . \ _| |_| |\  | |__| | | . \ |__| | |\  | |__| | | |__| |/ ____ \| |  | | |____ 
|_|\_\_____|_| \_|\_____| |_|\_\____/|_| \_|\_____|  \_____/_/    \_\_|  |_|______|                                                                                                                                
)";
        const std::string line = "***************************************************************************************************************************";
        const std::string planeArt = R"(
       __|__
--@--@--(_)--@--@--
)";

       const std::string clearPlane = R"(
            
                   
)";

        const std::string monkeyArt = R"(    || __   ||
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
    ||      ||)";

        const std::string endGameAscii = R"(
   _____          __  __ ______    ______      ________ _____  _ 
  / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \| |
 | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) | |
 | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  /| |
 | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \|_|
  \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_(_)
  )";

    public:

        Display(int X, int Y){ //150 columns // 30 rows
            x=X;
            y=Y;
        }

        //method to form cstrings into display format planned and print at correct place in array.
        void drawDisplay(){

            print_at(0,3,planeHPIndicator);
            //print_at(0,2,playerName[RandIndex]);
            std::vector<std::vector<char>> headingArr = create_array_from_string(headingASCII);
            print_at(20,0,headingArr);
            print_at(110,0,levelIndicator);
            //print_at(110,2,monkeyName[RandIndex]);
            print_at(110,3,monkeyHPIndicator);
            print_at(0,7,line);
            std::vector<std::vector<char>> planeArr = create_array_from_string(planeArt);
            print_at(0,15,planeArr);
            setCurrentYPos(15);
            std::vector<std::vector<char>> monkeyArr = create_array_from_string(monkeyArt);
            print_at(100,8,monkeyArr);
            print_at(0,31,line);
        }

        //method to move plane object up and down array based on KBM input.
        int characterAction(DWORD startTime) {
            char input = KBMInput(startTime);
            int Ypos = getCurrentYPos(); // move the declaration outside the switch block
            switch (input) {
                case 'w':
                    if(Ypos >= 8){
                        print_at(0, Ypos, clearPlane);
                        Ypos--;
                        setCurrentYPos(Ypos);
                        print_at(0, Ypos, planeArt);
                        break;
                    }
                    else{
                        print_at(0, Ypos, planeArt);
                        break;
                    }

                case 's':
                    if(Ypos <= 26){
                        print_at(0, Ypos, clearPlane);
                        Ypos++;
                        setCurrentYPos(Ypos);
                        print_at(0, Ypos, planeArt);
                        break;
                        }
                    else{
                        print_at(0, Ypos, planeArt);
                        break;
                    }

                case ' ':
                    Ypos += 2;
                    print_at(20,Ypos,planeProjectile);
                    break;

                case 'p':
                    break;

                default: // handle unrecognized input
                    break;
            }
            counter++;
            return counter;
        }

        void shootMonkeyProj(DWORD startTime, int projRow){

            if(counter==5){
                projRow = randProjRow();
            }
            DWORD currentTime = GetTickCount();
            DWORD elapsedTime = currentTime - startTime;
            int currentProjNum = getProjectileNum();
            for(int i=0;i<currentProjNum;i++){
                if(elapsedTime>getProjectileFrq()){
                    print_at(99, projRow, mProjectile);  //99 is furthest right column before monkey
                    counter = 0;
                }
            }
        }

        // char updateProjectiles(){

        //     int projPosArr[2] = &getPlaneProjectilePostitions(projectileTopLeft, projectileRegion,'-');
        //     COORD pProjPos = {projPosArr[0],projPosArr[1]}
        //     if (pProjPos.X != 82){
        //         print_at(pProjPos.X,pProjPos.Y,' ');
        //         pProjPos.X++;
        //         print_at(pProjPos.X,pProjPos.Y,'-');
        //         return 'o';
        //     }
        //     else{
        //         print_at(pProjPos.X,pProjPos.Y,' ');
        //         return 'h';
        //     }
        // }

        void nextLevel(){
            int currentLevel = getLevel();
            currentLevel++;
            setLevel(currentLevel);
            int currentHP = getHitPoints();
            setHitPoints(currentHP + 2);
        }

        bool endGame(){

            int stopRun;
            //print_at(15,125,endGameAscii);
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