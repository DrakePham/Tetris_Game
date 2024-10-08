#include "block.h"
#include "position.h"

class LBlock : public Block{
public:
    LBlock(){
        id = 1;
        cells = {
            {0, {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)}},
            {1, {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)}},
            {2, {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)}},
            {3, {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}}
        };
        move(0,3);
    }
};