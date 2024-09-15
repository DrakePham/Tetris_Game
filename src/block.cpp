#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 3;
    colors = getCellColors();
    rowOffset = 0;
    columnOffset = 0;
}


void Block::draw()
{
    vector<Position> value = getCellPositions();
        for (Position pos : value)
        {
            Color cellColor = colors[id];
            DrawRectangle(pos.column * cellSize + 1, pos.row * cellSize + 1, cellSize - 1, cellSize - 1, cellColor);
        }   
}

void Block::move(int row, int column)
{
    rowOffset += row;
    columnOffset += column;
}

vector<Position> Block::getCellPositions()
{
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;
    for (Position pos : tiles)
    {
        movedTiles.push_back(Position(pos.row + rowOffset, pos.column + columnOffset));
    }
    return movedTiles;
}


