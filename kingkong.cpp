#include <iostream>
#include "headers.h"

using namespace std;

int main(){

    bool stop = false;

    //create objects
    Display output(30,250);
    Character monkey(5);
    Projectile monkeyProj(')');
    Character plane(3);
    Projectile planeProj('-');


    //draw display based on level of game.
    if(output.getLevel() == 1){
        output.drawDisplay();
    }

    else{
        //main loop for game running
        while(stop == false){

            if(plane.getHitPoints() == 0){
                //stop = output.endGame();
            }

            else if(monkey.getHitPoints() == 0){
                // move to next level. Increase monkey hp and projectile frequency
                output.nextLevel();
                output.drawDisplay();
            }

            else{
                output.moveCharacter(); // if plane needs to stay still what is getch() timeout.
                monkey.shootMonkeyProj();
                output.moveProjectiles();
                //check if collision and set hp decrement
            }
        }
    }
    

    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins
//  test.cpp by Peter Jones (Iteration 1 and 2)