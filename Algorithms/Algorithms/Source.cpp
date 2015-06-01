#include <iostream>
#include "Header.h"

using namespace std;



int main()
{
	int choice;
	
	while (true)
	{
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "Which Question: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Question1();
			break;

		case 2:
			Question2();
			break;

		case 3:
			Question3();
			break;

		}
	}
}