#include "grid.h"
#include "cell.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

void Initialize(GRID* g)
{
	g->colls = 9;
	g->rows = 9;
	g->totalNumberOfMine = 0;
	g->cells = (CELL**)malloc(sizeof(CELL*) * g->rows);
	for (int row = 0; row < g->rows; row++)
	{
		g->cells[row] = (CELL*)malloc(sizeof(CELL) * g->colls);

		for (int coll = 0; coll < g->colls; coll++)
		{
			InitCells(&g->cells[row][coll], row, coll);
			MarkingCell(&g->cells[row][coll]);
		}
	}
}

void DisplayGrid(const GRID* g)
{
	for (int row = 0; row < g->rows; row++)
	{
		for (int coll = 0; coll < g->colls; coll++)
		{
			std::cout << "{" << (g->cells[row][coll]).Display << "}";
		}
		std::cout << std::endl;
	}
}

int ChangeCell(GRID* g, int row, int coll, int action)
{
	if (row >= g->rows || coll >= g->colls)
	{
		std::cout << "ERROR (UNVALID COORD)" << std::endl;
		return 0;
	}
	else if (action != 1 && action != 2)
	{
		std::cout << "ERROR (UNVALID ACTION)" << std::endl;
		return 0;
	}
	else
	{
		if (action == 1)
		{
			(g->cells[row][coll]).isRevealed = true;
			(g->cells[row][coll]).isMarked = false;
			MarkingCell(&g->cells[row][coll]);
			return 1;
		}
		else if (action == 2)
		{
			(g->cells[row][coll]).isMarked = true;
			(g->cells[row][coll]).isRevealed = false;
			MarkingCell(&g->cells[row][coll]);
			return 1;
		}
	}
	

}

void GenerateMap(GRID* g, int row, int coll)
{
	g->totalNumberOfMine = (g->rows * g->colls) * 0.15;
}