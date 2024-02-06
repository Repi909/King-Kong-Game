#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>

#ifndef KBM_H
#define KBM_H

class KBM {

public:
    KBM();
    char input;
    char KBMInput(DWORD startTime);
};

#endif