#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include"Chip.h"
#include"Board.h"

class Player
{
private:
	string name;
	char color;

public:
	Player();

	string getName() const;
	char getColor() const;

	void setName(string input);
	void setColor(char input);

	string toString();
};

#endif