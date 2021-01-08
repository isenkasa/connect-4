#include "Chip.h"

Chip::Chip()
{
	color = BLANK;
}

Chip::Chip(char color)
{
	this->color = color;
}

void Chip::setColor(char color)
{
	this->color = color;
}

int Chip::getColor() const
{
	return color;
}

string Chip::toString()
{
	stringstream stream;
	stream << color;

	string returnStr = stream.str();

	return returnStr;
}
