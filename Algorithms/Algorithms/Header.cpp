#include <iostream>
#include "Header.h"

using namespace std;



void Question1()
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Question 1" << endl;
	cout << endl;
	cout << "a)" << endl;
	cout << endl;
	cout << "the algorithm sorts the list, if there is nothing in the list the algorithm" << endl;
	cout << "returns 0" << endl;
	cout << endl;
	cout << "b)" << endl;
	cout << endl;
	cout << "IF list is empty RETURN null" << endl;
	cout << "WHILElist not sorted DO" << endl;
	cout << "FOR EACH consecutive pair of elements IN the list" << endl;
	cout << "IF the elements in the pair are not in the correct order THEN" << endl;
	cout << "Reverse the order of the pair of elements in the list" << endl;
	cout << endl;
	cout << "c)" << endl;
	cout << endl;
	cout << "NO!!!" << endl;
	char list[] = {31, 41, 59, 26, 41, 59};

	cout << list << endl;
	cout << Algorithm(*list) << endl;
	cout << endl;
}

void Question2()
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Question 2" << endl;
	cout << endl;
	cout << "1. check if the game is completed" << endl;
	cout << "2. check if three 'X' or 'O' are in a row or all slots are full, if so then" << endl;
	cout << "complete game" << endl;
	cout << "3. player takes turn, check if input is empty, if it is then place 'X' or 'O'" << endl;
	cout << "in selected slot, if not repeat turn" << endl;
	cout << endl;
}



void Question3()
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Question 3" << endl;
	cout << endl;
	cout << "WHILE game incomplete" << endl;
	cout << "	IF all slots full" << endl;
	cout << "		RETURN draw" << endl;
	cout << "	IF three 'O' in a row" << endl;
	cout << "		RETURN 'Player1 wins'  " << endl;
	cout << "	IF three 'X' in a row" << endl;
	cout << "		RETURN 'Player2 wins'  " << endl;
	cout << "	WHILE turn incompleted" << endl;
	cout << "		INPUT from the user" << endl;
	cout << "		IF the selected slot is empty" << endl;
	cout << "			the slot EQUALS 'X' or 'O' " << endl;
	cout << "			Complete turn" << endl;
	cout << endl;
}






char Algorithm(char *list, char *list2)
{
	bool sorted = false;
	int i = 0;
	int j = 1;
cout << *list << endl;
	/*
	if (list = 0)
	{
		return 0;
	}
	

	
	while (sorted = false)
	{
		if (list[i] > list[j])
		{



		}
		sorted = true;
	}
	*/
	return *list;
}