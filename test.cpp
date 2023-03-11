#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<vector<char>> create_array_from_string(const string& asciiArt) {
    vector<vector<char>> array;
    stringstream stringconvert(asciiArt);
    string line;
    while (getline(stringconvert, line)) {
        vector<char> char_line;
        for (char c : line) {
            char_line.push_back(c);
        }
        array.push_back(char_line);
    }
    return array;
}

void print_array_at_position(const vector<vector<char>>& array, int x, int y) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array[i].size(); ++j) {
            if (i == y && j == x) {
                cout << "@";
            } else {
                cout << array[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    string asciiArt = "###\n#.#\n###\n";
    vector<vector<char>> array = create_array_from_string(asciiArt);
    int x = 10, y = 12;
    print_array_at_position(array, x, y);
    return 0;
}
