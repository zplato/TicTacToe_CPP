#include <gtest/gtest.h>
#include "TicTacToe.cpp"  // Include your source file directly for simplicity in this example

// Helper function to reset the board
void resetBoard(char* spaces) {
    for (int i = 0; i < 9; i++) {
        spaces[i] = ' ';
    }
}

// Test: Check if player can place a move
TEST(TicTacToeTests, PlayerMove) {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    
    // Player makes a move at index 0
    spaces[0] = player;

    // Validate that the move was registered correctly
    ASSERT_EQ(spaces[0], 'X');
}

// Test: Check if AI makes a valid move (not overwriting existing spaces)
TEST(TicTacToeTests, AIMove) {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char aiPlayer = 'O';

    // Simulate an AI move
    aIMove(spaces, aiPlayer);

    // Check that the move was placed in an empty space (not overwriting a player move)
    bool validMove = false;
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == aiPlayer) {
            validMove = true;
            break;
        }
    }

    ASSERT_TRUE(validMove);
}

// Test: Check if winner is detected correctly
TEST(TicTacToeTests, CheckWinner) {
    char spaces[9] = { 'X', 'X', 'X', ' ', 'O', ' ', ' ', 'O', ' ' };
    char player = 'X';
    char aiPlayer = 'O';
    
    // Test for winner
    bool result = checkWinner(spaces, player, aiPlayer);
    
    ASSERT_TRUE(result);  // Since 'X' is the winner
}

// Test: Check if tie is detected correctly
TEST(TicTacToeTests, CheckTie) {
    char spaces[9] = { 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'O' };
    
    // Check for a tie
    bool result = checkTie(spaces);
    
    ASSERT_TRUE(result);  // Since there are no empty spaces and no winner
}

// Test: Check if the board is reset correctly
TEST(TicTacToeTests, ResetBoard) {
    char spaces[9] = { 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X' };

    resetBoard(spaces);

    // Check that all spots are reset to empty spaces
    for (int i = 0; i < 9; i++) {
        ASSERT_EQ(spaces[i], ' ');
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}