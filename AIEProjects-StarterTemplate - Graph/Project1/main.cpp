
#include "Game1.h"


int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(1200, 800, false, "Game1");
	pGame->RunGame();
	delete pGame;

	return 0;
};