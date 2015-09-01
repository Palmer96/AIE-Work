/*------------------------------------------------------------------------------------*
*    ______   _   ____        ______   _____   ____        ______   _____   _____    *
*   |__  __| | | |  __|  __  |__  __| |  _  | |  __|  __  |__  __| |  _  | |  ___|   *
*     |  |   | | | |__  |__|   |  |   | |_| | | |__  |__|   |  |   | |_| | |  _|_    *
*     |__|   |_| |____|        |__|   |_| |_| |____|        |__|   |_____| |_____|   *
*                                                                                    *
*------------------------------------------------------------------------------------*/


#include <iostream>
//#include "Header.h"

int main()
{
	system("COLOR f0");
	/*
	Game1 Game;
	while (true)
	{
		Game.Intro();
		while (true)
		{
			if (Game.GameComplete == false)
			{
				Game.PlayerInput();
			}
			else
			{
				break;
				Game.Reset();
				Game.GameComplete() = false;
			}
		}
	}

	*/
	int iGame = 0;
	while (true)
	{
	system("cls");

	char cEmpty = ' ';
	char cLocation[3][3] = { cEmpty };
	int iPlayer1 = 1;
	int iPlayer2 = 1;
	char cPlayer_X = 88;
	char cPlayer_O = 79;
	char cSmile = 2;
	while (true)
	{
	std::cout << " " << std::endl;
	std::cout << "_______________________________________________________________________________" << std::endl;
	std::cout << "  ______   _   ____        ______   _____   ____        ______   _____   _____ " << std::endl;
	std::cout << " |__  __| | | |  __|  __  |__  __| |  _  | |  __|  __  |__  __| |  _  | |  ___|" << std::endl;
	std::cout << "   |  |   | | | |__  |__|   |  |   | |_| | | |__  |__|   |  |   | |_| | |  _|_ " << std::endl;
	std::cout << "   |__|   |_| |____|        |__|   |_| |_| |____|        |__|   |_____| |_____|" << std::endl;
	std::cout << "_______________________________________________________________________________" << std::endl; // 78 38 35  43
	std::cout << " " << std::endl;
	std::cout << "                       __________________________________ " << std::endl;
	std::cout << "                      |                 |                |" << std::endl;
	std::cout << "                      |    1 | 2 | 3  " << "  |  " << "  X | O | X   |" << std::endl;
	std::cout << "                      |   ----------- " << "  |  " << " -----------  |" << std::endl;
	std::cout << "                      |    4 | 5 | 6  " << "  |  " << "  O | " << cSmile << " | O   |" << std::endl;
	std::cout << "                      |   ----------- " << "  |  " << " -----------  |" << std::endl;
	std::cout << "                      |    7 | 8 | 9  " << "  |  " << "  X | O | X   |" << std::endl;
	std::cout << "                      |_________________|________________|" << std::endl;
	std::cout << " " << std::endl;


	if (cLocation[0][0] == cPlayer_X && cLocation[1][0] == cPlayer_X && cLocation[2][0] == cPlayer_X ||
	cLocation[0][1] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[2][1] == cPlayer_X ||
	cLocation[0][2] == cPlayer_X && cLocation[1][2] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[0][0] == cPlayer_X && cLocation[0][1] == cPlayer_X && cLocation[0][2] == cPlayer_X ||
	cLocation[1][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[1][2] == cPlayer_X ||
	cLocation[2][0] == cPlayer_X && cLocation[2][1] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[0][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[2][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[0][2] == cPlayer_X)
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "Player 1 Wins" << std::endl;
	break;
	}
	else if (cLocation[0][0] == cPlayer_O && cLocation[1][0] == cPlayer_O && cLocation[2][0] == cPlayer_O ||
	cLocation[0][1] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[2][1] == cPlayer_O ||
	cLocation[0][2] == cPlayer_O && cLocation[1][2] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[0][0] == cPlayer_O && cLocation[0][1] == cPlayer_O && cLocation[0][2] == cPlayer_O ||
	cLocation[1][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[1][2] == cPlayer_O ||
	cLocation[2][0] == cPlayer_O && cLocation[2][1] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[0][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[2][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[0][2] == cPlayer_O)
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "Player 2 Wins" << std::endl;
	break;
	}
	else if (((cLocation[0][0] == cPlayer_O) || (cLocation[0][0] == cPlayer_X)) &&
	((cLocation[1][0] == cPlayer_O) || (cLocation[1][0] == cPlayer_X)) &&
	((cLocation[2][0] == cPlayer_O) || (cLocation[2][0] == cPlayer_X)) &&
	((cLocation[0][1] == cPlayer_O) || (cLocation[0][1] == cPlayer_X)) &&
	((cLocation[1][1] == cPlayer_O) || (cLocation[1][1] == cPlayer_X)) &&
	((cLocation[2][1] == cPlayer_O) || (cLocation[2][1] == cPlayer_X)) &&
	((cLocation[0][2] == cPlayer_O) || (cLocation[0][2] == cPlayer_X)) &&
	((cLocation[1][2] == cPlayer_O) || (cLocation[1][2] == cPlayer_X)) &&
	((cLocation[2][2] == cPlayer_O) || (cLocation[2][2] == cPlayer_X)))
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "It's a Draw" << std::endl;
	break;
	}
	{
	std::cout << "  " << std::endl;
	std::cout << "Player 1: ";
	std::cin >> iPlayer1;
	std::cout << "  " << std::endl;

	if (iPlayer1 > 0 && iPlayer1 < 10)
	{
	switch (iPlayer1)
	{
	case 1:
	if (cLocation[0][0] != cPlayer_X && cLocation[0][0] != cPlayer_O)
	cLocation[0][0] = cPlayer_X;
	break;
	case 2:
	if (cLocation[1][0] != cPlayer_X && cLocation[1][0] != cPlayer_O)
	cLocation[1][0] = cPlayer_X;
	break;
	case 3:
	if (cLocation[2][0] != cPlayer_X && cLocation[2][0] != cPlayer_O)
	cLocation[2][0] = cPlayer_X;
	break;
	case 4:
	if (cLocation[0][1] != cPlayer_X && cLocation[0][1] != cPlayer_O)
	cLocation[0][1] = cPlayer_X;
	break;
	case 5:
	if (cLocation[1][1] != cPlayer_X && cLocation[1][1] != cPlayer_O)
	cLocation[1][1] = cPlayer_X;
	break;
	case 6:
	if (cLocation[2][1] != cPlayer_X && cLocation[2][1] != cPlayer_O)
	cLocation[2][1] = cPlayer_X;
	break;
	case 7:
	if (cLocation[0][2] != cPlayer_X && cLocation[0][2] != cPlayer_O)
	cLocation[0][2] = cPlayer_X;
	break;
	case 8:
	if (cLocation[1][2] != cPlayer_X && cLocation[1][2] != cPlayer_O)
	cLocation[1][2] = cPlayer_X;
	break;
	case 9:
	if (cLocation[2][2] != cPlayer_X && cLocation[2][2] != cPlayer_O)
	cLocation[2][2] = cPlayer_X;
	break;
	}
	}
	else
	std::cout << "please slect a number between 1 and 9" << std::endl;




	std::cout << "  " << cLocation[0][0] << " | " << cLocation[1][0] << " | " << cLocation[2][0] << std::endl;
	std::cout << " ----------- " << std::endl;
	std::cout << "  " << cLocation[0][1] << " | " << cLocation[1][1] << " | " << cLocation[2][1] << std::endl;
	std::cout << " ----------- " << std::endl;
	std::cout << "  " << cLocation[0][2] << " | " << cLocation[1][2] << " | " << cLocation[2][2] << std::endl;

	}

	if (cLocation[0][0] == cPlayer_X && cLocation[1][0] == cPlayer_X && cLocation[2][0] == cPlayer_X ||
	cLocation[0][1] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[2][1] == cPlayer_X ||
	cLocation[0][2] == cPlayer_X && cLocation[1][2] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[0][0] == cPlayer_X && cLocation[0][1] == cPlayer_X && cLocation[0][2] == cPlayer_X ||
	cLocation[1][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[1][2] == cPlayer_X ||
	cLocation[2][0] == cPlayer_X && cLocation[2][1] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[0][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[2][2] == cPlayer_X ||
	cLocation[2][0] == cPlayer_X && cLocation[1][1] == cPlayer_X && cLocation[0][2] == cPlayer_X)
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "Player 1 Wins" << std::endl;
	break;
	}
	else if (cLocation[0][0] == cPlayer_O && cLocation[1][0] == cPlayer_O && cLocation[2][0] == cPlayer_O ||
	cLocation[0][1] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[2][1] == cPlayer_O ||
	cLocation[0][2] == cPlayer_O && cLocation[1][2] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[0][0] == cPlayer_O && cLocation[0][1] == cPlayer_O && cLocation[0][2] == cPlayer_O ||
	cLocation[1][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[1][2] == cPlayer_O ||
	cLocation[2][0] == cPlayer_O && cLocation[2][1] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[0][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[2][2] == cPlayer_O ||
	cLocation[2][0] == cPlayer_O && cLocation[1][1] == cPlayer_O && cLocation[0][2] == cPlayer_O)
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "Player 2 Wins" << std::endl;
	break;
	}
	else if (((cLocation[0][0] == cPlayer_O) || (cLocation[0][0] == cPlayer_X)) &&
	((cLocation[1][0] == cPlayer_O) || (cLocation[1][0] == cPlayer_X)) &&
	((cLocation[2][0] == cPlayer_O) || (cLocation[2][0] == cPlayer_X)) &&
	((cLocation[0][1] == cPlayer_O) || (cLocation[0][1] == cPlayer_X)) &&
	((cLocation[1][1] == cPlayer_O) || (cLocation[1][1] == cPlayer_X)) &&
	((cLocation[2][1] == cPlayer_O) || (cLocation[2][1] == cPlayer_X)) &&
	((cLocation[0][2] == cPlayer_O) || (cLocation[0][2] == cPlayer_X)) &&
	((cLocation[1][2] == cPlayer_O) || (cLocation[1][2] == cPlayer_X)) &&
	((cLocation[2][2] == cPlayer_O) || (cLocation[2][2] == cPlayer_X)))
	{

	std::wcout << "GAMEOVER" << std::endl;
	std::wcout << "It's a Draw" << std::endl;
	break;
	}


	{
	std::cout << "  " << std::endl;
	std::cout << "Player 2: ";
	std::cin >> iPlayer2;
	std::cout << "  " << std::endl;


	if (iPlayer2 > 0 && iPlayer2 < 10)
	{
	switch (iPlayer2)
	{
	case 1:
	if (cLocation[0][0] != cPlayer_X && cLocation[0][0] != cPlayer_O)
	cLocation[0][0] = cPlayer_O;
	break;
	case 2:
	if (cLocation[1][0] != cPlayer_X && cLocation[1][0] != cPlayer_O)
	cLocation[1][0] = cPlayer_O;
	break;
	case 3:
	if (cLocation[2][0] != cPlayer_X && cLocation[2][0] != cPlayer_O)
	cLocation[2][0] = cPlayer_O;
	break;
	case 4:
	if (cLocation[0][1] != cPlayer_X && cLocation[0][1] != cPlayer_O)
	cLocation[0][1] = cPlayer_O;
	break;
	case 5:
	if (cLocation[1][1] != cPlayer_X && cLocation[1][1] != cPlayer_O)
	cLocation[1][1] = cPlayer_O;
	break;
	case 6:
	if (cLocation[2][1] != cPlayer_X && cLocation[2][1] != cPlayer_O)
	cLocation[2][1] = cPlayer_O;
	break;
	case 7:
	if (cLocation[0][2] != cPlayer_X && cLocation[0][2] != cPlayer_O)
	cLocation[0][2] = cPlayer_O;
	break;
	case 8:
	if (cLocation[1][2] != cPlayer_X && cLocation[1][2] != cPlayer_O)
	cLocation[1][2] = cPlayer_O;
	break;
	case 9:
	if (cLocation[2][2] != cPlayer_X && cLocation[2][2] != cPlayer_O)
	cLocation[2][2] = cPlayer_O;
	break;
	}
	}
	else
	std::cout << "please slect a number between 1 and 9" << std::endl;;

	std::cout << "  " << cLocation[0][0] << " | " << cLocation[1][0] << " | " << cLocation[2][0] << std::endl;
	std::cout << " ----------- " << std::endl;
	std::cout << "  " << cLocation[0][1] << " | " << cLocation[1][1] << " | " << cLocation[2][1] << std::endl;
	std::cout << " ----------- " << std::endl;
	std::cout << "  " << cLocation[0][2] << " | " << cLocation[1][2] << " | " << cLocation[2][2] << std::endl;

	}

	}
	system("pause");
	}
}
