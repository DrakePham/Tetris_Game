#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    
    try{
        InitWindow(500, 620, "Tetris Game");
       
        SetTargetFPS(60);

        Font font = LoadFontEx("../Front/monogram.ttf", 64, 0, 0);

        Game game = Game();



        while (!WindowShouldClose())
        {
            UpdateMusicStream(game.music);
            game.handleInput();
            if(eventTriggered(0.2)){
                game.moveBlockDown();
            }

            BeginDrawing();
            ClearBackground(darkBlue);
            DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
            DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
            if(game.isGameOver){
                DrawTextEx(font, "GAME", {370, 450}, 38, 2, WHITE);
                DrawTextEx(font, "OVER", {370, 500}, 38, 2, WHITE);
            }
            
            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
            
            DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
            DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
            DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

            game.draw();

            EndDrawing();
        }
        
        CloseWindow();
    }catch(const char* msg){
        std::cerr << msg << std::endl;
    }
    
    return 0;


}


// emcc -o snake.html main.cpp -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os \
// -I /Users/thongpham/Downloads/raylib/src -I /Users/thongpham/Downloads/raylib/src/external \
// -L /Users/thongpham/Downloads/raylib/src -s USE_GLFW=3 -s ASYNCIFY \
// -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --preload-file Graphics --preload-file Sounds \
// --shell-file /Users/thongpham/Downloads/raylib/src/shell.html \
// -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' \
// -s EXPORTED_RUNTIME_METHODS=ccall

// emcc src/*.cpp -o tetris.html -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os \
// -I /Users/thongpham/Downloads/raylib/src -I /Users/thongpham/Downloads/raylib/src/external \
// -L /Users/thongpham/Downloads/raylib/src/web -s USE_GLFW=3 -s ASYNCIFY \
// -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 \
// --shell-file /Users/thongpham/Downloads/raylib/src/shell.html \
// -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' \
// -s EXPORTED_RUNTIME_METHODS=ccall \
// /Users/thongpham/Downloads/raylib/src/web/libraylib.a -s USE_GLFW=3 -DPLATFORM_WEB

// emcc src/*.cpp -o /web/tetris.html -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os \
// -I /Users/thongpham/Downloads/raylib/src -I /Users/thongpham/Downloads/raylib/src/external \
// -L /Users/thongpham/Downloads/raylib/src/web -s USE_GLFW=3 -s ASYNCIFY \
// -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 \
// --shell-file /Users/thongpham/Downloads/raylib/src/shell.html \
// -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' \
// -s EXPORTED_RUNTIME_METHODS=ccall \
// /Users/thongpham/Downloads/raylib/src/web/libraylib.a -s USE_GLFW=3 -DPLATFORM_WEB

// python3 -m http.server 8000
