#include <iostream>
#include "Rooms.h"
#include "String.h"


Rooms::Rooms()
{
	RoomName = "Unknown";
	roomNum = 0;
}
Rooms::~Rooms()
{

}



void Rooms::RoomStart()
{
	std::cout << " " << std::endl;



	String string = " ";
	Rooms room;

while (true)
	{
	string.ReadFromConsole();
	string.ToLower();



	std::cout << std::endl;

	
		if (string.EqualTo("go north") == true)
		{
			room.NextRoom();

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

void Rooms::NextRoom()
{



}


void Rooms::Map(int Location)
{
	switch (Location)
	{
	case 1:
		std::cout << "       ___        " << std::endl;
		std::cout << "      |___|___    " << std::endl;
		std::cout << "      |___|___|       " << std::endl;
		std::cout << "      |_X_|       " << std::endl;

		break;
	case 2:
		std::cout << "       ___        " << std::endl;
		std::cout << "      |___|___        " << std::endl;
		std::cout << "      |_X_|___|       " << std::endl;
		std::cout << "      |___|       " << std::endl;
		break;
	case 3:
		std::cout << "       ___        " << std::endl;
		std::cout << "      |___|___        " << std::endl;
		std::cout << "      |___|_X_|       " << std::endl;
		std::cout << "      |___|       " << std::endl;
		break;
	case 4:
		std::cout << "       ___        " << std::endl;
		std::cout << "      |_X_|___        " << std::endl;
		std::cout << "      |___|___|       " << std::endl;
		std::cout << "      |___|       " << std::endl;
		break;
	}
	


}