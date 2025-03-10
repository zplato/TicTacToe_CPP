
// Standard Libraries
#include <iostream>
#include <ctime> 



// Function Declarations
void drawBoard(char* spaces);
void playerMove(char* spaces, char player); 
void AIMove(char* spaces, char player);
bool checkWinner(char *spaces, char player, char computer); 
bool checkTie(char *spaces); 

// Function Definitions 
void drawBoard(char* spaces)
{
	std::cout << "\n"; 
	std::cout << "     |     |     " << '\n'; 
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "\n";
}

void playerMove(char* spaces, char player)
{
	int number; 
	do {
		std::cout << "Enter a spot to place the marker (1-9):";
		std::cin >> number; 
		number--; // Since array starts at 0 

		// Check if the space the user chose is occupied
		if (spaces[number] == ' ')
		{
			// Empty 
			spaces[number] = player; // Players Marker 
			break; 
		}

	} while (!number > 0 || !number < 8);
}

void aIMove(char* spaces, char player)
{
	int number; 
	srand(time(0)); // Seed the random number 

	while (true)
	{
		number = rand() % 9; // give me a number between 0 and 8 
		if (spaces[number] == ' ')
		{
			spaces[number] = player; 
			break; 
		}
	}


}

bool checkWinner(char* spaces, char player, char computer)
{
	// ROWS 
	if ((spaces[0] == spaces[1] && spaces[1] == spaces[2]) && spaces[0] != ' ')
	{
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[3] == spaces[4] && spaces[4] == spaces[5]) && spaces[3] != ' ')
	{
		spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[6] == spaces[7] && spaces[7] == spaces[8]) && spaces[6] != ' ')
	{
		spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}

	// COLUMNS 
	else if ((spaces[0] == spaces[3] && spaces[3] == spaces[6]) && spaces[6] != ' ')
	{
		spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[1] == spaces[4] && spaces[4] == spaces[7]) && spaces[7] != ' ')
	{
		spaces[7] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[2] == spaces[5] && spaces[5] == spaces[8]) && spaces[8] != ' ')
	{
		spaces[8] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}

	// DIAGONALS 
	else if ((spaces[0] == spaces[4] && spaces[4] == spaces[8]) && spaces[8] != ' ')
	{
		spaces[8] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[2] == spaces[4] && spaces[4] == spaces[6]) && spaces[6] != ' ')
	{
		spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
	}
	else
		return false;

	return true; 
}

bool checkTie(char* spaces)
{
	int spaces_length = sizeof(spaces) / sizeof(spaces[0]); 
	for (int i = 0; i < spaces_length-1; i++) // Iterate from 0 to 8 
	{
		if (spaces[i] == ' ')
			return false;  // Return false here b/c we found at least one empty space 
	}
	std::cout << "ITS A TIE!" << std::endl; 
	return true; 
}



int main()
{
	// 9 space board 
	char spaces[9] = { ' ', ' ',' ', ' ',' ', ' ',' ', ' ',' ' };
	char player = 'X'; 
	char aI = 'O';
	bool running = true; 

	drawBoard(spaces); 

	while(running)
	{
		// 
		playerMove(spaces, player); 
		drawBoard(spaces);

		if (checkWinner(spaces, player, aI))
		{
			running = false; 
			break; 
		}
		else if (checkTie(spaces))
		{
			running = false; 
			break; 
		}

		aIMove(spaces, aI); 
		drawBoard(spaces); 

		if (checkWinner(spaces, player, aI))
		{
			running = false;
			break;
		}
		else if (checkTie(spaces))
		{
			running = false;
			break;
		}

	}

	return 0; 
}