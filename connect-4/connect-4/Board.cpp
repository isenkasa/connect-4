#include "Board.h"

int Board::firstColumn = 5;
int Board::secondColumn = 5;
int Board::thirdColumn = 5;
int Board::fourthColumn = 5;
int Board::fifthColumn = 5;
int Board::sixthColumn = 5;
int Board::seventhColumn = 5;

// Constructor that initializes the board places all to BLANK
Board::Board()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			chips[i][j].setColor(BLANK);
		}
	}
}

/**
* Converts Chip Color to string
* 
* @return string of chip color
*/
string Board::toString()
{
	string str, modifiedStr = "";

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			stringstream stream;
			stream << (char)chips[i][j].getColor();
			str = stream.str();

			modifiedStr += str + " ";
			str = "";
			if (j == COLUMNS - 1)
			{
				modifiedStr += "\n";
			}
		}
	}

	return modifiedStr;
}

/**
* Simulates the drop of the Chip into the Board
* 
* @param drop is the chip being dropped
* @param slot is the slot in which the chip goes
* 
* @return 0 for failure, 1 for success
*/
int Board::dropChip(Chip drop, int slot)
{
	// Drop in the first slot
	if (slot == 1)
	{
		if (firstColumn < 0)
		{
			// Failure, column can't be negative
			return 0;
		}
		else
		{
			chips[firstColumn][slot - 1] = drop;
			firstColumn--;
			return 1;
		}
	}

	// Drop in the second slot
	if (slot == 2)
	{
		if (secondColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[secondColumn][slot - 1] = drop;
			secondColumn--;
			return 1;
		}
	}

	// Drop in the third slot
	if (slot == 3)
	{
		if (thirdColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[thirdColumn][slot - 1] = drop;
			thirdColumn--;
			return 1;
		}
	}

	// Drop in the fourth slot
	if (slot == 4)
	{
		if (fourthColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[fourthColumn][slot - 1] = drop;
			fourthColumn--;
			return 1;
		}
	}

	// Drop in the fifth slot
	if (slot == 5)
	{
		if (fifthColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[fifthColumn][slot - 1] = drop;
			fifthColumn--;
			return 1;
		}
	}

	// Drop in the sixth slot
	if (slot == 6)
	{
		if (sixthColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[sixthColumn][slot - 1] = drop;
			sixthColumn--;
			return 1;
		}
	}

	// Drop in the seventh slot
	if (slot == 7)
	{
		if (seventhColumn < 0)
		{
			return 0;
		}
		else
		{
			chips[seventhColumn][slot - 1] = drop;
			seventhColumn--;
			return 1;
		}
	}
}

/**
* Determines if there is a winner or if the match has ended on a draw
* 
* @return 0 if it is a draw, 1 if Player 1 wins, 2 if Player 2 wins
*/
int Board::isWinner()
{
	// NO WINNER CASE
	int flag = 0;
	int count = 0;
	while (flag != 1)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				if (chips[i][j].getColor() != 'X')
				{
					count++;

					if (count == TOTAL_SPACES)
					{
						resetColumns();
						return 0;
					}
				}
				else flag = 1;
			}
		}
	}

	// Determining the Winner

	// horizontal
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// RED WINS 
			if ((chips[i][j].getColor() + chips[i][j + 1].getColor() + chips[i][j + 2].getColor() + chips[i][j + 3].getColor()) == RED_TOTAL)
			{
				resetColumns();
				return 1;
			}

			// GOLD WINS 
			if ((chips[i][j].getColor() + chips[i][j + 1].getColor() + chips[i][j + 2].getColor() + chips[i][j + 3].getColor()) == GOLD_TOTAL)
			{
				resetColumns();
				return 2;
			}
		}
	}

	// vertical
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// RED WINS 
			if ((chips[j][i].getColor() + chips[j + 1][i].getColor() + chips[j + 2][i].getColor() + chips[j + 3][i].getColor()) == RED_TOTAL)
			{
				resetColumns();
				return 1;
			}

			// GOLD WINS 
			if ((chips[j][i].getColor() + chips[j + 1][i].getColor() + chips[j + 2][i].getColor() + chips[j + 3][i].getColor()) == GOLD_TOTAL)
			{
				resetColumns();
				return 2;
			}
		}
	}

	// diagonal 1
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// RED WINS 
			if ((chips[i][j].getColor() + chips[i + 1][j + 1].getColor() + chips[i + 2][j + 2].getColor() + chips[i + 3][j + 3].getColor()) == RED_TOTAL)
			{
				resetColumns();
				return 1;
			}

			// GOLD WINS 
			if ((chips[i][j].getColor() + chips[i + 1][j + 1].getColor() + chips[i + 2][j + 2].getColor() + chips[i + 3][j + 3].getColor()) == GOLD_TOTAL)
			{
				resetColumns();
				return 2;
			}
		}
	}

	// diagonal 2
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 7; j++)
		{
			for (int j = 0; j < 3; j++)
			{
				// RED WINS 
				if ((chips[i][j].getColor() + chips[i + 1][j + 1].getColor() + chips[i + 2][j + 2].getColor() + chips[i + 3][j + 3].getColor()) == RED_TOTAL)
				{
					resetColumns();
					return 1;
				}

				// GOLD WINS 
				if ((chips[i][j].getColor() + chips[i + 1][j + 1].getColor() + chips[i + 2][j + 2].getColor() + chips[i + 3][j + 3].getColor()) == GOLD_TOTAL)
				{
					resetColumns();
					return 2;
				}
			}
		}
	}

	// diagonal 3
	for (int i = 3; i < ROWS; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// RED WINS 
			if ((chips[i][j].getColor() + chips[i - 1][j + 1].getColor() + chips[i - 2][j + 2].getColor() + chips[i - 3][j + 3].getColor()) == RED_TOTAL)
			{
				resetColumns();
				return 1;
			}

			// GOLD WINS 
			if ((chips[i][j].getColor() + chips[i - 1][j + 1].getColor() + chips[i - 2][j + 2].getColor() + chips[i - 3][j + 3].getColor()) == GOLD_TOTAL)
			{
				resetColumns();
				return 2;
			}
		}
	}

	// diagonal 4
	for (int i = 3; i < ROWS; i++)
	{
		for (int j = 3; j < COLUMNS; j++)
		{
			// RED WINS 
			if ((chips[i][j].getColor() + chips[i - 1][j - 1].getColor() + chips[i - 2][j - 2].getColor() + chips[i - 3][j - 3].getColor()) == RED_TOTAL)
			{
				resetColumns();
				return 1;
			}

			// GOLD WINS 
			if ((chips[i][j].getColor() + chips[i - 1][j - 1].getColor() + chips[i - 2][j - 2].getColor() + chips[i - 3][j - 3].getColor()) == GOLD_TOTAL)
			{
				resetColumns();
				return 2;
			}
		}
	}
}

// Resets the columns to their initial state
void Board::resetColumns()
{
	firstColumn = 5;
	secondColumn = 5;
	thirdColumn = 5;
	fourthColumn = 5;
	fifthColumn = 5;
	sixthColumn = 5;
	seventhColumn = 5;
}