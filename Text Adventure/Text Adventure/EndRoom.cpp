#include <iostream>
#include "String.h"
#include "Rooms.h"
#include "EndRoom.h"
using namespace std;



EndRoom::EndRoom()
{

	int roomNum = 0;
}
EndRoom::~EndRoom()
{

}



void EndRoom::RoomStart()
{
	std::cout << " " << std::endl;



	String string = " ";
	Rooms room;

	std::cout << "Welcome to Start Room										type 'help' if you need assistence" << std::endl;
	std::cout << "There is a door infront of you, it seems to be unlocked" << std::endl;
	std::cout << "What will you do" << std::endl;

	while (true)
	{
		string.ReadFromConsole();
		string.ToLower();



		std::cout << std::endl;


		if (string.EqualTo("go north") == true)
		{
			NextRoom();

		}
		else if (string.EqualTo("go south") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("go east") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("go west") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("look") == true)
		{
			std::cout << "you see and empty room with a door infront of you" << std::endl;
		}
		else if (string.EqualTo("map") == true)
		{
			Map(1);
		}
		else if (string.EqualTo("help") == true)
		{
			std::cout << "         Help Menu" << std::endl;
			std::cout << "       --------------" << std::endl;
			std::cout << "     help = Help Menu" << std::endl;
			std::cout << "     look = search the Room" << std::endl;
			std::cout << "      map = Show Map" << std::endl;
			std::cout << " go north = Travel North" << std::endl;
			std::cout << " go south = Travel South" << std::endl;
			std::cout << " go east  = Travel East" << std::endl;
			std::cout << " go west  = Travel West" << std::endl;
			std::cout << " " << std::endl;
		}
		else
			std::cout << "failed" << std::endl;

		system("pause");
		system("cls");
	}



}

void EndRoom::NextRoom()
{



}

