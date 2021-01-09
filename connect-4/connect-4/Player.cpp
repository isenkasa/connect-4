#include"Player.h"

// Constructor to initialize the name and chip color for Player
Player::Player()
{
	name = "Player X";
	color = RED;
}

/**
* Getter for Player Name
*
* @return the Player Name
*/
string Player::getName() const
{
	return name;
}

/**
* Getter for Player Color 
*
* @return the Player Color
*/
char Player::getColor() const
{
	return color;
}

/**
* Setter for Player Name
* 
* @param input - the name to be passed in
*/
void Player::setName(string input)
{
	name = input;
}

/**
* Setter for Player Color
* 
* @param input - the color to be passed in
*/
void Player::setColor(char input)
{
	color = input;
}

/**
* Converts the player name and color to string
* 
* @return the player name and color
*/
string Player::toString()
{
	string returnString;
	returnString = name + " (" + color + ") ";

	return returnString;
}
