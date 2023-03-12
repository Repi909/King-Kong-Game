//Unbuffered keyboard input from conio.h using the getch().
#include "headers.h"

//default constructor
KBM::KBM() {
    input;
}

//unbuffered keyboard input with timeout of 500ms.
char KBM::KBMInput(DWORD startTime){
            
    DWORD currentTime = GetTickCount(); //gets current tick count of program
    DWORD elapsedTime = currentTime - startTime;    //calculates elapsed time from current tick count - start tick count
    while(1)
        if (_kbhit()){ // Check if a key has been pressed
            input = getch(); // Read the character
            break;
        
        if (elapsedTime > 500){ //checks if 500ms has passed since function executed last.
            input = 'p'; // Timeout occurred
            break;
        }
    }
    return input;
}