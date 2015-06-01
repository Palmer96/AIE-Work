#include <iostream>
#include "String.h"
#include "Rooms.h"
#include "StartRoom.h"



StartRoom::StartRoom()
{

	int roomNum = 0;
}
StartRoom::~StartRoom()
{

}



void StartRoom::RoomStart()
{
	std::cout << " " << std::endl;



	String string = " ";
	StartRoom room;

	std::cout << "Welcome to Start Room										type 'help' if you need assistence" << std::endl;
	std::cout << "There is a door infront of you, it seems to be unlocked" << std::endl;
	std::cout << "What will you do" << std::endl;

	while (true)
	{
		string.ReadFromConsole();
		string.ToLower();



		std::cout << std::endl;


		if (string.EqualTo("north") == true)
		{
			room.NextRoom();

		}
		else if (string.EqualTo("south") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("east") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("west") == true)
		{
			std::cout << "There is a wall in your way" << std::endl;
		}
		else if (string.EqualTo("look") == true)
		{
			std::cout << "you see and empty room with a door infront of you" << std::endl;
		}
		else if (string.EqualTo("map") == true)
		{
			room.Map(1);
			std::cout << std::endl;
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

void StartRoom::NextRoom()
{
	//Rooms room1;
	//room1.roomNum = 2;


}

