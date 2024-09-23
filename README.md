# Tetris Game in C++

This project is a simple implementation of the classic Tetris game in C++, using the raylib library for graphics. The game features object-oriented design to manage the different components of the game. 
<!-- such as the board, tetrominoes, and the game controller. -->


## Entity Relationships

In this Tetris implementation, the key entities and their relationships are as follows:

1. **Game**:  
   - The central entity that controls the entire game logic. It manages the game state, such as the current score, the `currentBlock` (active falling block), the `nextBlock` (upcoming block), and the `grid` (the playing area).
   - **Relationships**: 
     - The `Game` class **contains** a `Grid`, `currentBlock`, `nextBlock`, and **interacts** with `Block` and `Grid` to handle game logic, collision detection, block locking, and row clearing.
     - **Game** uses the `Grid` to place the falling blocks and render the board, while managing the `Block` entities (such as moving, rotating, and dropping them).

2. **Grid**:
   - Represents the 2D game area where blocks fall and are placed.
   - **Relationships**: 
     - The `Grid` class **interacts** with the `Block` class, placing the blocks in the correct positions, checking for filled rows, and clearing them when necessary.
     - The `Grid` also **uses** `Color` to render the blocks within the grid cells.

3. **Block**:
   - Represents individual Tetris blocks, also known as Tetrominoes, with distinct shapes and rotation states.
   - **Relationships**:
     - The `Block` class **contains** multiple `Position` objects that define the coordinates of the block's individual cells.
     - It **uses** `Color` to assign a specific color to the block for rendering.
     - Specific block types (e.g., `SBlock`, `IBlock`, etc.) **inherit** from the `Block` class to define their unique shapes and rotation behavior.

4. **Position**:
   - Represents the row and column coordinates of each cell in a block.
   - **Relationships**: 
     - `Position` is **used by** the `Block` class to define the layout of each block.
     - Each block is made up of multiple `Position` objects to represent its shape.

5. **Color**:
   - Defines a set of color constants used to differentiate blocks and render the grid cells.
   - **Relationships**:
     - `Color` is **used by** both the `Grid` and `Block` classes to render the game elements with appropriate colors.


For more detailed information on how these entities relate to each other, please refer to the document in the link below:

[Entity Relationship Document](https://drive.google.com/file/d/1isX77r-dmLTyshxRkZInhUHbUg-3qX3a/view?usp=sharing)

## How to Run

### macOS

1. **Install Raylib**:
   - Use Homebrew to install Raylib:
     ```bash
     brew install raylib
     ```

2. **Clone the Repository**:
   - Open a terminal and clone the repository:
     ```bash
     git clone https://github.com/DrakePham/Tetris_Game.git
     cd Tetris_Game
     ```

3. **Compile the Game**:
   - If there's a `Makefile` provided:
     ```bash
     make
     ```
   - Alternatively, compile manually:
     ```bash
     clang++ -std=c++17 -o tetris main.cpp -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
     ```

4. **Run the Game**:
   - After compiling, run the executable:
     ```bash
     ./tetris
     ```

### Windows

1. **Install Raylib**:
   - Download the Raylib installer from the [official site](https://github.com/raysan5/raylib/releases) or use a package manager like `vcpkg`:
     ```bash
     vcpkg install raylib
     ```

2. **Clone the Repository**:
   - Open Command Prompt or PowerShell and clone the repository:
     ```bash
     git clone https://github.com/DrakePham/Tetris_Game.git
     cd Tetris_Game
     ```

3. **Compile the Game**:
   - If there’s a `Makefile`, you can use MinGW or any other compiler that supports `make`:
     ```bash
     mingw32-make
     ```
   - Alternatively, compile manually using g++ or Visual Studio:
     ```bash
     g++ -std=c++17 -o tetris.exe main.cpp -lraylib -lopengl32 -lgdi32 -lwinmm
     ```

4. **Run the Game**:
   - After compiling, run the executable:
     ```bash
     tetris.exe
     ```



## Controls

- **Arrow Keys**: Move tetromino left or right
- **Up Arrow**: Rotate tetromino
- **Down Arrow**: Speed up tetromino fall


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.