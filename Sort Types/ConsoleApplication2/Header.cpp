#include <iostream>
#include "Header.h"
using namespace std;



void BubbleSort(int *Array, int num)
{
	int count = 0;
	bool swapped = true;
	cout << endl << "The Array: ";
	for (int i = 0; i < num; i++)
		cout << Array[i] << " ";
	cout << endl << endl;

	while (swapped)
	{
		swapped = false;

		for (int i = 0; i < (num - 1); i++)
		{
			count++;
			cout << count << ": ";
			if (Array[i] > Array[i + 1])
			{
				Swap(Array[i], Array[i + 1]);
				swapped = true;
			}

			for (int i = 0; i < num; i++)
				cout << Array[i] << " ";
			cout << endl;
		}

	}
	cout << endl << "Final: ";
	for (int i = 0; i < num; i++)
		cout << Array[i] << " ";
	cout << endl;


}


void Swap(int Array1, int Array2)
{
	int temp;
	temp = Array1;
	Array1 = Array2;
	Array2 = temp;
}




int Partition(int * const iArray, int left, int right)
{
	//x = pivot value
	int x = iArray[right];
	int num = right + 1;
	int count = 0;

	//set the wall as the left most element
	//i = wall
	int i = left - 1;

	//iterate from the element to the left of the wall, to the final element in this subarray (r)
	for (int j = left; j < right; j++)
	{
		//if the current element is less than the pivot
		if (iArray[j] <= x)
		{
			//move the wall across one
			i++;

			//swap current element to the first on the right of the wall
			Swap(iArray[i], iArray[j]);



		}
		count++;
		cout << count << ": ";
		for (int i = 0; i < num; i++)
			cout << iArray[i] << " ";
		cout << endl;
	}

	//once complete, we insert the pivot at the wall location by swapping pivot and wall

	Swap(iArray[i + 1], iArray[right]);


	count++;
	cout << count << ": ";
	for (int i = 0; i < num; i++)
		cout << iArray[i] << " ";
	cout << endl;

	//return the pivot location
	return i + 1;

}

void QuickSort(int * const iArray, int l, int r)
{
	//if l > r, it means the left side of the subarray IS greater than the right side, so we must have gone too far. We're done.
	//jump back up to the previous level of recursion.
	if (l < r)
	{
		//calculate the new partition 
		int q = Partition(iArray, l, r);

		//then we perform the same algorithm on the subarray to the left of the wall
		QuickSort(iArray, l, q - 1);

		//and the subarray to the right of the wall
		QuickSort(iArray, q + 1, r);
	}

}