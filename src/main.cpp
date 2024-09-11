#include <raylib.h>
#include "grid.h"

int main()
{
    
    try{
        InitWindow(300, 600, "Tetris Game");
        Color darkBlue = {0, 121, 241, 255};
       
        SetTargetFPS(60);

        Grid grid = Grid();
        grid.printGrid();
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(darkBlue);
            EndDrawing();
        }
        
        CloseWindow();
    }catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    
    return 0;


}