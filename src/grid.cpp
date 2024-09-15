#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();
    InitializeGrid();
}

void Grid::InitializeGrid()
{

    if (numRows <= 0 || numCols <= 0)
    {
        throw "Error: Invalid grid dimensions";
    }
   
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            if(grid[row] == nullptr ){
                throw "Error: Grid initialization failed";
            }
            grid[row][column] = 0;
        }
    }
}

void Grid::printGrid()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}


void Grid::draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            Color cellColor = colors[cellValue];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, cellColor);
        }
    }
}

bool Grid::isCellOutOfBounds(int row, int column)
{
    if (row < 0 || row >= numRows || column < 0 || column >= numCols)
    {
        return true;
    }
    return false;
}
