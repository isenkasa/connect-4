#include "Chip.h"

// Sets the color of the chip to BLANK
Chip::Chip()
{
	color = BLANK;
}

/**
* Overloaded constructor for Chip
* 
* @param color to be passed in
*/
Chip::Chip(char color)
{
	this->color = color;
}

/**
* Setter for Chip Color
* 
* @param color to be passed in
*/
void Chip::setColor(char color)
{
	this->color = color;
}

/**
* Getter for Chip Color
* 
* @return color of the Chip
*/
int Chip::getColor() const
{
	return color;
}

/**
* Converts the Chip Color to string
* 
* @return string formatted color
*/
string Chip::toString()
{
	stringstream stream;
	stream << color;

	string returnStr = stream.str();

	return returnStr;
}
