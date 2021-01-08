#pragma once

#ifndef BOARD_H
#define BOARD_H

#include"Chip.h"

class Board
{
private:
	static int firstColumn, secondColumn, thirdColumn, fourthColumn, fifthColumn, sixthColumn, seventhColumn;
	Chip chips[ROWS][COLUMNS];
public:
	Board();

	string toString();
	int dropChip(Chip drop, int slot);
	int isWinner();
};

#endif