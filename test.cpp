#include <iostream>

using namespace std;

const char* create_cstring(std::string asciiArt){
    const char* cstring = asciiArt.c_str();  //headingASCII = 6 rows 73 columns. monkeyArt = 24 rows 24 columns 
    return cstring;
}

int main(){

    string AsciiArt = "|| (__/ ||\n||  | | :-'''-.\n||==| \\/-=-.   \\ \n||  |(_|o o/   |_\n||   \\/ '  \\   ,_)\n||====\\ ^  /__/\n||     ;--'  `-.||    /      .  \\\n||===;        \\  \\\n||   |         | |\n    || .-\\ '     _/_/\n|:'  _;.    (_  \\\n/  .'  `;\\   \\_/\n|_ /     |||  |\\\\\n/  _)=====|||  | ||\n/  /|      ||/  / //\n \\_/||      ( `-/ ||\n    ||======/  /  \\ .-.\njgs ||      \\_/    \'-'/\n    ||      ||      `'`\n    ||======||\n    ||      ||          ";
    string headingASCII = " _  ___               _  __                    ____                      \n| |/ /_ _ __   __ _  | |/ /___  _ __   __ _   / ___| __ _ _ __ ___   ___ \n| ' /| | '_ \\ / _` | | ' // _ \\| '_ \\ / _` | | |  _ / _` | '_ ` _ \\ / _ \\ \n| . \\| | | | | (_| | | . | (_) | | | | (_| | | |_| | (_| | | | | | |  __/\n|_|\\_|_|_| |_|\\__, | |_|\\_\\___/|_| |_|\\__, |  \\____|\\__,_|_| |_| |_|\\___|\n              |___/                   |___/                              ";
    string heading = create_cstring(headingASCII);
    cout << heading << endl;
    string cstring = create_cstring(AsciiArt);
    cout << cstring;
    
}
