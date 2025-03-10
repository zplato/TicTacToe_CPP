// TicTacToe.h
// Contains all function declarations and shared variables for the TicTacToe game

#ifndef TICTACTOE_H
#define TICTACTOE_H

void drawBoard(char* spaces);
void playerMove(char* spaces, char player); 
void aIMove(char* spaces, char player);
bool checkWinner(char *spaces, char player, char computer); 
bool checkTie(char *spaces); 

#endif // TICTACTOE_H