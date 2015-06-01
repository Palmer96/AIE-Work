#include <iostream>

using namespace std;


int main()
{
	char Input[64];
	cout << " " << endl;
	cin >> Input;

	int Num[64];

	for (int i = 0; i < strlen(Input); i++)
	{
		Num[i] = Input[i];

		cout << Input[i] << " " << Num[i] << endl;
	}

	for (int i = 0; i < strlen(Input); i++)
	{
		if (Num[i] >= 128)
		{
			cout << 1;
			Num[i] -= 128;
		}
		else
			cout << 0;

		if (Num[i] >= 64)
		{
			cout << 1;
			Num[i] -= 64;
		}
		else
			cout << 0;

		if (Num[i] >= 32)
		{
			cout << 1;
			Num[i] -= 32;
		}
		else
			cout << 0;

		if (Num[i] >= 16)
		{
			cout << 1;
			Num[i] -= 16;
		}
		else
			cout << 0;

		if (Num[i] >= 8)
		{
			cout << 1;
			Num[i] -= 8;
		}
		else
			cout << 0;

		if (Num[i] >= 4)
		{
			cout << 1;
			Num[i] -= 4;
			cout << Num[i];
		}
		else
			cout << 0;

		if (Num[i] >= 2)
		{
			cout << 1;
			Num[i] -= 2;
			cout << Num[i];
		}
		else
			cout << 0;

		if (Num[i] = 1)
		{
			
			cout << 1;
			Num[i] -= 1;
			cout << Num[i];
		}
		else
			cout << 0;



		cout << " ";
	}




	system("pause");
}