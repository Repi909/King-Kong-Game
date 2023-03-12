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

    bool Enable;
    int level = 1;
    COORD coord;

    public:
        Setup();
        void show_cursor (bool Enable);
        std::vector<std::vector<char>> create_array_from_string(const std::string& asciiArt);
        void print_at (int x, int y, std::string String);
        void print_at (int x, int y, const std::vector<std::vector<char>>& array);
        void print_at (int arrayRow, int arrayCol, int number);
        int setLevel(int setlevel);
        int getLevel();
};
class KBM { 
        
    public:
        char input;
        char KBMInput(DWORD startTime);
};

class Projectile{
    private:
        int projectileNum = 1;
        int projectileFrq = 5000;
    
    public:
        std::string mProjectile = ")";
        int getProjectileFrq();
        int getProjectileNum();
        void setProjectileNum(int pNum);
        void setProjectileFrq(int pFrq);
        int randProjRow();
        void projCollision();
        std::vector<std::vector<COORD>> getPlaneProjectilePositions(COORD projectileTopLeft, int projectileRegion[], std::string projectile);
};

class Character: public Setup, public Projectile{

    private:
        int hitPoints;
        int currentY_pos;

    public:
        Character(int hp);
        Character();
        void setHitPoints(int hp);
        int getHitPoints();
        void setCurrentYPos(int yPos);
        int getCurrentYPos();
};

class Display: public Character, public KBM {

    private:
        int x;
        int y;
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

        Display(int X, int Y);
        Display();
        void drawDisplay();
        int characterAction(DWORD startTime);
        void shootMonkeyProj(DWORD startTime, int projRow);
        //char updateProjectiles();
        void nextLevel();
        bool endGame();
};

#endif