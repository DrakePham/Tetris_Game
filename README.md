# Tetris Game in C++

This project is a simple implementation of the classic Tetris game in C++, using the raylib library for graphics. The game features object-oriented design to manage the different components of the game. 
<!-- such as the board, tetrominoes, and the game controller. -->


## Entity Relationships

In this Tetris implementation, the key entities and their relationships are as follows:

<!-- 1. **Game Board**: Manages the grid where the tetrominoes are placed. It stores the state of each cell (empty or filled) and handles logic such as line clearing.
   
2. **Tetromino**: Represents the falling blocks (tetrominoes). Each tetromino consists of four blocks, and they can be rotated and moved across the game board.

3. **Game Controller**: Handles user input (keyboard commands) and manages the game state (whether the game is running, paused, or over).

The relationship between these entities is that the **Tetromino** objects are placed onto the **Game Board**, and their movement and rotation are controlled by the **Game Controller**. The game board also checks for filled lines and clears them, updating the game state accordingly. -->

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