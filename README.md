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

To compile and run the game, follow these steps:
1. Make sure you have raylib installed.
2. Clone this repository.
3. Compile the game using the provided `Makefile` or manually compile with your compiler of choice.
4. Run the executable.

## Controls

- **Arrow Keys**: Move tetromino left or right
- **Up Arrow**: Rotate tetromino
- **Down Arrow**: Speed up tetromino fall


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.