#include "Display.h"

//constructor
Display::Display(int X, int Y){
    x=X;
    y=Y;

    COORD projectileTopLeft = {20,8};
    int projectileRegion[2] = {82,22};

    int counter = 0;
    //int projRow;

    int RandIndex = rand() % 6;
    std::string pname;
    std::string mname;
    //const char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
    //const char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};
    
    bool stop = false;
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

}
//default constructor
Display::Display(){

    x=150;  //default columns
    y=30;   //default rows

    COORD projectileTopLeft = {20,8};   //top left coord for projectile region
    int projectileRegion[2] = {82,22};  //region where projectiles can be found

    int counter = 0;    //loop counter for rand() execution
    //int projRow;        //projectile row

    int RandIndex = rand() % 6;
    std::string pname;
    std::string mname;
    //const char* monkeyName[5] = {"King Kong", "Curious George", "Rafiki", "Wukong", "Donkey Kong"};
    //const char* playerName[5] = {"Amelia Earhart", "Maverick", "Dusty Crophopper", "Auntie Mabel and Pippin", "Orville and Wilbur Wright"};
    
    bool stop = false;  //stop condition for endGame method

    //int x;      // number of columns
    //int y;      // number of rows

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

}

//method to print all strings into display format planned and at correct place on console.
void Display::drawDisplay(){
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
//method to move plane or shoot projectile based on KBM input.
int Display::characterAction(DWORD startTime) {
    char input = KBMInput(startTime);                       //gets input from KBMInput()
    int Ypos = getCurrentYPos();                            //gets current Y position of plane
    switch (input) {                                        //switch case for each keyboard input.
        case 'w':                                           //moves plane upwards by clearing plane and reprinting on line above
            if(Ypos >= 8){                                  //stops plane from moving out of bounds.
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

        case 's':                                           //moves plane downwards by clearing plane and reprinting on line below
            if(Ypos <= 26){                                 //stops plane from moving out of bounds.
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

        case ' ':                                           //shoots projectile by printing projectile at current Y position
            Ypos += 2;                                      // +=2 to make the projectile line up with bottom of plane
            print_at(20,Ypos,planeProjectile);
            break;

        case 'p':                                           //timeout case to keep code from hanging whilst waiting for kbm input
            break;
            
        default: // handle unrecognized input
            break;
    }
    counter++;                                              //counter for shootMonkeyProj to stop rand() from executing constantly.
    return counter;
}

//method to shoot monkey projectile based on time passed vs projectile frequency. Only shoots specified number of projectiles which increases with level.
void Display::shootMonkeyProj(DWORD startTime, int projRow){
    if(counter==5){
        projRow = randProjRow();
    }
    DWORD currentTime = GetTickCount();     //gets current tick count
    DWORD elapsedTime = currentTime - startTime;    //gets elapsed time from current ticks - start ticks
    int currentProjNum = getProjectileNum();    //gets number of projectiles to print
    if(elapsedTime>getProjectileFrq()){         //print only when elapsed time is greater than frequency
        for(int i=0;i<currentProjNum;i++){
            print_at(99, projRow, mProjectile);  //99 is furthest right column before monkey
            counter = 0;
        }
    }
}

// char updateProjectiles()
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

// method to setup next level once monkeyHP == 0 by getting current level and incrementing whilst also increasing hitpoints
void Display::nextLevel(){
    int currentLevel = getLevel();
    setLevel(currentLevel++);               //increases current level 
    int currentHP = getHitPoints();
    setHitPoints(currentHP + 2);            //increases monkey hitpoints by 2 at each level
    int currentProjFrq = getProjectileFrq();
    setProjectileFrq(currentProjFrq++);     //increases projectile frequency at each level by 1
    int currentProjNum = getProjectileNum();
    if(currentLevel % 2 == 0){              //increases projectile number by 1 if 2 levels have passed.
        setProjectileNum(currentProjNum++);
    }
}

//method to display endgame screen.
bool Display::endGame(){
    int stopRun;
    system("cls");
    print_at(15,75,endGameAscii);   //prints endgame ascii
    std::cout << "Final Level: " + getLevel();  //prints final score
    std::cout << "Press Enter to end game.";
    std::cin >> stopRun;
    if(stopRun == 10){  //ends program if enter pressed.
        stop = true;
    }
    return stop;
}