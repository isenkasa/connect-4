#pragma once

#ifndef CHIP_H
#define CHIP_H

#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;

const int RED_TOTAL = 328, GOLD_TOTAL = 284;
const int TOTAL_SPACES = 42;
const int ROWS = 6, COLUMNS = 7;
const char BLANK = 'X', RED = 'R', GOLD = 'G';

class Chip
{
private:
	char color;
public:
	Chip();
	Chip(char color);
	void setColor(char color);
	int getColor() const;
	string toString();
};

#endif