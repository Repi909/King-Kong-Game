#include <iostream>
#include "headers.h"

using namespace std;

int main(){

    bool stop = false;

    //create objects
    Display output(250,30);
    Character monkey(5, ')');
    Character plane(3, '-');

    //draw display based on level of game.
    if(output.getLevel() == 1){
        output.drawDisplay();
    }

    else{
        //main loop for game running
        while(stop == false){

            if(plane.getHitPoints() == 0){
                stop = endGame();
            }

            else if(monkey.getHitPoints() == 0){
                // move to next level. Increase monkey hp and projectile frequency
                output.nextLevel();
                output.drawDisplay();
            }

            else{
                plane.moveCharacter(); // if plane needs to stay still what is getch() timeout.
                monkey.shootMonkeyProj();
                //check if collision and set hp decrement
            }
        }
    }
    

    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins
//  test.cpp by Peter Jones (Iteration 1 and 2)