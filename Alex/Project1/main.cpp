
#include "Game1.h"
#include <iostream>


int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(1650, 1050, true, "Game1");
	pGame->RunGame();
	delete pGame;




	return 0;

};