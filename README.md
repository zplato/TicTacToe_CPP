# TicTacToe_CPP

A C++ implementation of the classic Tic Tac Toe game, featuring both player and AI modes. The project includes unit tests written using GoogleTest to ensure functionality and correctness. The game logic is encapsulated in a simple command-line interface with basic gameplay features such as move validation, winner detection, and a tie check.

## Features

- **Two-player mode**: Play Tic Tac Toe with a friend.
- **Single-player mode**: Play against a simple AI opponent.
- **AI Move**: AI makes valid moves while attempting to block the player and create winning opportunities.
- **Winner detection**: The game automatically checks for winners.
- **Tie detection**: The game can detect if the game ends in a tie.
- **Board reset**: After a game ends, the board can be reset for a new round.

## Prerequisites

Before you can build and run the project, ensure that the following tools are installed:

- **CMake** (Version 3.10 or higher)
- **C++17 compliant compiler**
- **GoogleTest** (automatically fetched as part of the build process)

## Project Structure

```bash
TicTacToe_CPP/
├── CMakeLists.txt           # The main build file for CMake
├── README.md                # This file
├── src/                     # Source code for the game logic
│   └── TicTacToe.cpp        # Main implementation of the game
├── test/                    # Unit tests for the game
│   └── test_Tic_Tac_Toe.cpp # Tests written with GoogleTest
└── build/                   # The build directory (created when compiling)

## Building the Project

1.  **Clone the repository (if applicable):**

    ```bash
    git clone [repository URL]
    cd TicTacToe_CPP
    ```

2.  **Create a build directory:**

    ```bash
    mkdir build
    cd build
    ```

3.  **Run CMake:**

    ```bash
    cmake ..
    ```

4.  **Build the project:**

    ```bash
    cmake --build . --config Debug # or Release
    ```

    * This will create two executables: `TicTacToeTest` (for running tests) and `TicTacToe_Game` (for playing the game).
    * It will also create a static library `TicTacToe_CPP_lib`.

## Running the Tests

1.  **Navigate to the `build` directory:**

    ```bash
    cd build
    ```

2.  **Run CTest:**

    ```bash
    ctest -V -C Debug # or Release
    ```

    * This will execute the unit tests defined in `test/test_Tic_Tac_Toe.cpp` using Google Test.

## Running the Game

1.  **Navigate to the `build/Debug` or `build/Release` directory:**

    ```bash
    cd build/Debug # or Release
    ```

2.  **Run the `TicTacToe_Game` executable:**

    ```bash
    ./TicTacToe_Game # On Linux/macOS
    TicTacToe_Game.exe # On Windows
    ```

    * This will start the Tic-Tac-Toe game.

    ## Future Improvements

* **Enhanced AI Logic:** Implement a more sophisticated AI algorithm for the computer player.
* **Graphical User Interface (GUI):** Create a GUI for a more user-friendly experience.
* **Input Validation:** Add input validation to prevent invalid player moves.
* **More Test Cases:** Increase the test coverage by adding more test cases, including edge cases and error handling.
* **Refactor code:** Refactor code to increase readability.

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.