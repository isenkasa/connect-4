#include"Chip.h"
#include"Board.h"
#include"Player.h"

const int PLAYER_MAX = 2;

int main()
{
	int game = 1;

	while (game == 1)
	{
		Player p[PLAYER_MAX];

		p[0].setName("Player 1");
		p[1].setName("Player 2");

		Chip blankChip(BLANK);
		Chip redChip(RED);
		Chip goldChip(GOLD);

		cout << "Connect Four Game!" << endl << endl;

		int choice;
		cout << "Select the color for Player 1 (1 for RED, 2 for GOLD): ";
		cin >> choice;

		while (choice < 1 || choice > 2)
		{
			cout << "Invalid input. please try again! Input: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			p[0].setColor(redChip.getColor());
			p[1].setColor(goldChip.getColor());
		}
		else if (choice == 2)
		{
			p[0].setColor(goldChip.getColor());
			p[1].setColor(redChip.getColor());
		}

		Board gameBoard;

		cout << p[0].getName() << " has the " << p[0].getColor() << " chip." << endl;
		cout << p[1].getName() << " has the " << p[1].getColor() << " chip." << endl << endl;

		cout << gameBoard.toString() << endl;
		int signal = 0;

		while (gameBoard.isWinner() != 0 && gameBoard.isWinner() != 1 && gameBoard.isWinner() != 2)
		{
			unsigned seed;

			cout << "Player " << (signal % 2) + 1 << " turn:" << endl;

			seed = time(0);
			srand(seed);

			// Player 1
			if ((signal % 2) == 0)
			{
				Chip gameChip(p[0].getColor());

				int slot;
				cout << "Enter the slot number you want to insert your chip in: ";
				cin >> slot;

				if (gameBoard.dropChip(gameChip, slot) == 0)
				{
					while (gameBoard.dropChip(gameChip, slot) == 0)
					{
						cout << "Invalid input. Try again: ";
						cin >> slot;

						gameBoard.dropChip(gameChip, slot);
					}
				}
				else
				{
					cout << "Success!" << endl;
				}
			}
			else
			{
				Chip gameChip(p[1].getColor());

				int slot;
				cout << "Enter the slot number you want to insert your chip in: ";
				cin >> slot;

				if (gameBoard.dropChip(gameChip, slot) == 0)
				{
					while (gameBoard.dropChip(gameChip, slot) == 0)
					{
						cout << "Invalid input. Try again: ";
						cin >> slot;

						gameBoard.dropChip(gameChip, slot);
					}
				}
				else
				{
					cout << "Success!" << endl;
				}
			}
			cout << gameBoard.toString() << endl;
			signal++;
		}

		if (gameBoard.isWinner() == 0)
		{
			cout << "There are no winners!" << endl;
		}
		else if (gameBoard.isWinner() == 1)
		{
			cout << p[0].getName() << " is the winner!" << endl;
		}
		else
		{
			cout << p[1].getName() << " is the winner!" << endl;
		}

		int playAgain;
		cout << "If you wish to play again, enter 1. If you wish to quit the game, enter a different number. Input: ";
		cin >> playAgain;

		game = playAgain;
	}

	system("pause");
	return 0;
}