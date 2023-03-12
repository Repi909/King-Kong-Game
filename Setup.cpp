#include "headers.h"

Setup::Setup() {
    Enable = false;
    level = 1;
    coord = {0, 0};
}
// show_cursor taken from Test.cpp written by Peter Jones
void Setup::show_cursor (bool Enable){
    if (Enable) printf ("\033[?25h");   //shows cursor in console
    else printf ("\033[?25l");          //hides cursor in console
    }

//takes mutli-line string AsciiArt and converts to an 2D vector array of chars.
std::vector<std::vector<char>> Setup::create_array_from_string(const std::string& asciiArt) {
    std::vector<std::vector<char>> array;   //initialize 2D vector array of chars.
    std::stringstream stringconvert(asciiArt);  // use stringstream to convert multi-line string into individual lines
    std::string line;
    while (getline(stringconvert, line)) {  //loops to take individual characters within each line and uses push.back to put them into a vector.
        std::vector<char> char_line;
        for (char c : line) {
            char_line.push_back(c);
        }
        array.push_back(char_line);     //vectors are then concatenated together to form 2D vector array.
    }
    return array;
}

// print_at adapted from Test.cpp written by Peter Jones
void Setup::print_at (int x, int y, std::string String){
    coord.X = x;    //define x coord
    coord.Y = y;    //define y coord
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //set cursor position using defined coords
    std::cout << String;
}

//overloaded print_at function to take value for string array.
void Setup::print_at (int x, int y, const std::vector<std::vector<char>>& array){
    coord.X = x;    //define x coord
    coord.Y = y;    //define y coord
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //set cursor position using defined coords
    for (int i = 0; i < array.size(); i++) {    //nested for loop to print each vector char array
        for (int j = 0; j < array[i].size(); j++) {
            std::cout << array[i][j];
        }
        coord.X = x;
        coord.Y = y++;  //increments coord.Y so next vector char array prints on line beneath at same coord.X
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}

//overloaded print_at function to take value for number.
void Setup::print_at (int x, int y, int number){
    coord.X = x;    //define x coord
    coord.Y = y;    //define y coord
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);   //set cursor position using defined coords
    std::cout << number;    //print number
}

//set method for level
int Setup::setLevel(int setlevel){
    level = setlevel;
    return level;
}

//get method for level
int Setup::getLevel(){
    return level;
}