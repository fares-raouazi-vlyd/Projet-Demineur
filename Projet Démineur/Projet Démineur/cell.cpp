#include "cell.h"
#include <iostream>
#include <cstdlib>

void InitCells(CELL* c, int row, int coll)
{
	c->x = row;
	c->y = coll;
	c->Display = ' ';
	c->isMarked = false;
	c->isMine = false;
	c->isRevealed = false;
	c->numberOfMine = 0;	
}

void MarkingCell(CELL* c)
{
	if (c->isMarked == true)
	{
		c->Display = 'F';
	}
	else if (c->isMine == true)
	{
		c->Display = '*';
	}
	else if (c->isRevealed == true)
	{
		c->Display = '@';
	}
	else
		c->Display = ' ';
}
