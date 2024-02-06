#pragma once

#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>

class Setup {

    bool Enable;
    int level = 1;
    COORD coord;

public:
    Setup();
    void show_cursor(bool Enable);
    std::vector<std::vector<char>> create_array_from_string(const std::string& asciiArt);
    void print_at(int x, int y, std::string String);
    void print_at(int x, int y, const std::vector<std::vector<char>>& array);
    void print_at(int arrayRow, int arrayCol, int number);
    int setLevel(int setlevel);
    int getLevel();
    void setCMDWindowSize();
};

#endif