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
    void setCell(int row, int column, int id);
    bool isCellEmpty(int row, int column);
    int clearFullRows();

private:
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;

    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowsDown(int row, int numRows);

};