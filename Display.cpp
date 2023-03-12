#include <headers.h>

Display::Display(int X, int Y){
    x=X;
    y=Y;

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

}

Display::Display(){

    x=150;  //default columns
    y=30;   //default rows

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

}

        //method to form cstrings into display format planned and print at correct place in array.
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
//method to move plane object up and down array based on KBM input.
int Display::characterAction(DWORD startTime) {
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

void Display::shootMonkeyProj(DWORD startTime, int projRow){
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
// 
void Display::nextLevel(){
    int currentLevel = getLevel();
    currentLevel++;
    setLevel(currentLevel);
    int currentHP = getHitPoints();
    setHitPoints(currentHP + 2);
}

bool Display::endGame(){
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