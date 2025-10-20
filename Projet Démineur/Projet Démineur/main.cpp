#include "cell.h"
#include "grid.h"
#include <iostream>
#include <cstdlib>

int AskDifficulty();
void AskPlayer(GRID* g)
{
	int valid = 0;
	while (valid == 0)
	{
		int x;
		int y;
		std::cout << "Give X and Y coord : " << std::endl;
		std::cin >> x;
		std::cout << std::endl;
		std::cin >> y;
		std::cout << std::endl;
		int action;
		std::cout << "What do you want to do ? 1 : Reveal | 2 : Flag" << std::endl;
		std::cin >> action;
		valid = ChangeCell(g, x, y, action);
	}
	
}
void GameLoop(GRID* g)
{
	bool lose = false;
	while(lose == false)
	{
		AskPlayer(g);
		DisplayGrid(g);
	}

}

int main()
{	
	GRID g;
	Initialize(&g);
	GameLoop(&g);
	return 0;
}