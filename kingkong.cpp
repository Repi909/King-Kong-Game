#include <iostream>
#include "headers.h"

using namespace std;

int main(){

    Display output(250,30);
    Character monkey(100, ')');
    Character plane(3, '-');

    //setup display and create objects
    if(output.getLevel() == 1){
        output.drawDisplay();
    }

    //main loop for game running
    while(monkey.getHitPoints() != 0 || plane.getHitPoints() != 0){
            
        plane.moveCharacter();

    }

    if(plane.getHitPoints() == 0){
            //end game and ask to play again
        output.setLevel(1);

    }

    else if(monkey.getHitPoints() == 0){
        // move to next level. Increase monkey hp and projectile frequency
        output.nextLevel();
        

    } 

    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins