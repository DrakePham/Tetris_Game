#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 3;
    colors = getCellColors();
}


void Block::draw()
{
    vector<Position> value = cells[rotationState];
        for (Position pos : value)
        {
            Color cellColor = colors[id];
            DrawRectangle(pos.column * cellSize + 1, pos.row * cellSize + 1, cellSize - 1, cellSize - 1, cellColor);
        }
    
}

