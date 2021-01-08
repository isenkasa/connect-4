#include"Player.h"

Player::Player()
{
	name = "Player X";
	color = RED;
}

string Player::getName() const
{
	return name;
}

char Player::getColor() const
{
	return color;
}

void Player::setName(string input)
{
	name = input;
}

void Player::setColor(char input)
{
	color = input;
}

string Player::toString()
{
	string returnString;
	returnString = name + " (" + color + ") ";

	return returnString;
}
