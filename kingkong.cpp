#include <iostream>
#include <vector>
#include "headers.h"

using namespace std;

int main(){

    bool stop = false;

    //create objects
    Display output(150,30);
    Character monkey(5);
    Character plane(3);

    //draw display based on level of game.
    system("cls"); //clear console
    output.show_cursor(false);
    output.drawDisplay();
    output.print_at(121,3,monkey.getHitPoints());
    output.print_at(117,0,output.getLevel());

    int startTime = 0; // Get current system time

    //main loop for game running
    while(stop == false){

        output.characterAction(startTime); // if plane needs to stay still what is getch() timeout.
        monkey.shootMonkeyProj();
        //char monkeyHit = output.updateProjectiles();
        // if (monkeyHit = 'h'){
        //     int hp = monkey.getHitPoints();
        //     monkey.setHitPoints(hp--);
        // }

        if(plane.getHitPoints() == 0){
           stop = output.endGame();
        }
        else if(monkey.getHitPoints() == 0){
            // move to next level. Increase monkey hp and projectile frequency
            output.nextLevel();
            output.drawDisplay();
        }
    }
    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins
//  test.cpp by Peter Jones (Iteration 1 and 2)