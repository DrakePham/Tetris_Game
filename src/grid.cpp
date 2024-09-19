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
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, cellColor);
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

void Grid::setCell(int row, int column, int id)
{
    grid[row][column] = id;
}

bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column] == 0){
        return true;
    }
    return false;
}

int Grid::clearFullRows()
{
    int completedRows = 0;
    for(int row = numRows - 1; row >= 0; row--){
        if(isRowFull(row)){
            clearRow(row);
            completedRows++;
        }else if(completedRows > 0){
            moveRowsDown(row, completedRows);
        }
    }
    return completedRows;
}

bool Grid::isRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[0][column] = 0;
    }
}

void Grid::moveRowsDown(int row, int numRows)
{
    for(int column  = 0; column < numCols; column++){
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

