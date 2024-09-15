#include <raylib.h>
#include "grid.h"
#include "TBlock.cpp"

int main()
{
    
    try{
        InitWindow(300, 600, "Tetris Game");
        Color darkBlue = {0, 121, 241, 255};
       
        SetTargetFPS(60);

        Grid grid = Grid();
        grid.printGrid();

        TBlock tBlock = TBlock();
        tBlock.move(4, 3);
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(darkBlue);
            grid.draw();
            tBlock.draw();
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
