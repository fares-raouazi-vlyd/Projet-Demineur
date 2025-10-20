#pragma once
#include <iostream>
#include <cstdlib>

struct CELL
{
	int x;
	int y;
	char Display;
	bool isMine;
	bool isRevealed;
	bool isMarked;
	int numberOfMine;
};

void InitCells(CELL* c, int row, int coll);
void MarkingCell(CELL* c);
