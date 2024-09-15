#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
#include <iostream>

using namespace std;

class Block{
public: 
    int id;
    map<int, vector<Position>> cells;

    Block();
    void move(int row, int column);
    void draw();
    vector<Position>  getCellPositions();
    void rotate();
    void undoRotate();
    int getRowOffset();
    int getColumnOffset();

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int columnOffset;

};