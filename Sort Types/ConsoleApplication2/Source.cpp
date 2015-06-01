#include <iostream>
#include <algorithm>
#include "Header.h"
using namespace std;




int main()
{
	//int iArray[] = { 2, 1, 8, 4, 6, 3, 5 };

	//int num = sizeof(iArray) / sizeof(int);
	bool swapped = true;
	int count;
	int iMin;


	while (true)
	{
		int iArray[] = { 2, 1, 8, 4, 6, 3, 5 };
		int num = sizeof(iArray) / sizeof(int);
		count = 0;
		int choice;
		cout << "1 = Bubble Sort"
			<< endl << "2 = Insertion Sort"
			<< endl << "3 = Selection Sort"
			<< endl << "4 = Quick Sort" << endl;
		cin >> choice;


		switch (choice)
		{
		case 1:
		{
			BubbleSort(iArray, num);
			/*
			swapped = true;
			cout << endl << "The Array: ";
			for (int i = 0; i < num; i++)
				cout << iArray[i] << " ";
			cout << endl << endl;
			while (swapped)
			{
				swapped = false;

				for (int i = 0; i < (num - 1); i++)
				{
					count++;
					cout << count << ": ";
					if (iArray[i] > iArray[i + 1])
					{
						Swap(iArray[i], iArray[i + 1]);
						swapped = true;
					}

					for (int i = 0; i < num; i++)
						cout << iArray[i] << " ";
					cout << endl;
				}

			}
			cout << endl << "Final: ";
			for (int i = 0; i < num; i++)
				cout << iArray[i] << " ";
			cout << endl;
			*/
			break;
		}
		case 2:
		{
			int Key;											// variables
			int j;
			cout << endl << "The Array: ";
			for (int i = 0; i < num; i++)						// Display Array
				cout << iArray[i] << " ";
			cout << endl << endl;

			for (int i = 1; i < num; i++)						// define variable
			{
				Key = iArray[i];							// what to check
				j = i - 1;									// where to find it

				count++;
				cout << count << ": ";
				while (j >= 0 && iArray[j] > Key)			// work way backwards
				{
					iArray[j + 1] = iArray[j];

					j--;
				}

				iArray[j + 1] = Key;						// put key in the middle

				for (int i = 0; i < num; i++)
					cout << iArray[i] << " ";
				cout << endl;
			}
			cout << endl << "Final: ";
			for (int i = 0; i < num; i++)
				cout << iArray[i] << " ";
			cout << endl << endl;
			break;
		}
		case 3:
		{
			cout << endl << "The Array: ";
			for (int i = 0; i < num; i++)					// Display Array
				cout << iArray[i] << " ";

			cout << endl << endl;

			for (int i = 0; i < num; i++)
			{
				iMin = i;

				count++;
				cout << count << ": ";
				for (int i = 0; i < num; i++)					// show result
					cout << iArray[i] << " ";
				cout << endl;

				for (int j = i; j < num; j++)
				{
					if (iArray[j] < iArray[iMin])			// if lower than min 
					{
						iMin = j;							// replace as min		

					}

				}
				Swap(iArray[i], iArray[iMin]);				//swap


			}
			cout << endl << "Final: ";
			for (int i = 0; i < num; i++)					// show result
				cout << iArray[i] << " ";
			cout << endl << endl;
			break;
		}




		case 4:
		{
			cout << endl << "The Array: ";
			for (int i = 0; i < num; i++)					// show result
				cout << iArray[i] << " ";
			cout << endl << endl;

			QuickSort(iArray, 0, num-1);

			cout << endl << "Final: ";
			for (int i = 0; i < num; i++)					// show result
				cout << iArray[i] << " ";
			cout << endl << endl;
			break;						
		}
		


		}
		cout << endl;
		system("pause");
		system("cls");
	}

}





