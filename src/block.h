#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block{
public: 
    int id;
    map<int, vector<Position>> cells;

    Block();

    void draw();

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;

};