#include <iostream>
#include "headers.h"

using namespace std;

int main(){

    Display output(250,30);
    Character monkey(100);
    Character plane(3);

    //setup display if starting from level 1
    if(output.getLevel() == 1){
        output.drawDisplay();
    }

    //main loop for game running
    else{
        while(monkey.getHitPoints() != 0 || plane.getHitPoints() != 0){
            
            plane.moveCharacter();
            
        }

        else if(){
            //end game and 
        }
    }
    

    return 0;
}


//references
//  https://www.youtube.com/watch?v=gWq0tJLsjRs snake game in 20mins