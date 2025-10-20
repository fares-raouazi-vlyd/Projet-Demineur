#pragma once
#include <iostream>
#include <cstdlib>
#include "cell.h"

struct GRID
{
	
	CELL** cells;
	int rows;
	int colls;
	int totalNumberOfMine;
};

void Initialize(GRID* g);

void DisplayGrid(const GRID* g);

int ChangeCell(GRID* g, int row, int coll, int action);

void GenerateMap(GRID* g, int row, int coll);