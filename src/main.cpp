#include <raylib.h>
#include "game.h"

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
        InitWindow(300, 600, "Tetris Game");
        Color darkBlue = {0, 121, 241, 255};
       
        SetTargetFPS(60);

        Game game = Game();
       
        while (!WindowShouldClose())
        {
            game.handleInput();
            if(eventTriggered(0.02)){
                game.moveBlockDown();
            }

            BeginDrawing();
            ClearBackground(darkBlue);
            
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
