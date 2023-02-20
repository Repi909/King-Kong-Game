#include <iostream>
#include <conio.h>
#include <windows.h>
#include "headers.h"

using namespace std;


int main(){


    Display game;

    game.setLevel(1);
    game.drawGrid();
    game.hideCursor();

    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins