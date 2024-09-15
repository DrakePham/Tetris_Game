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
    void move(int row, int column);
    void draw();
    vector<Position>  getCellPositions();

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;

};