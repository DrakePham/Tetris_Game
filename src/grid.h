#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

class Grid{
public:
    
    int grid[20][10];

    Grid();
    void InitializeGrid();
    void printGrid();
    void draw();
    bool isCellOutOfBounds(int row, int column);

private:
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;

};