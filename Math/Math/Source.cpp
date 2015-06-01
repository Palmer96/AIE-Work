#include <iostream>

using namespace std;




int MathAdd(int a, int b)
{
	return a + b;
}

int MathSub(int a, int b)
{
	return a - b;
}

int MathMul(int a, int b)
{
	return a * b;
}

int MathDiv(int a, int b)
{
	return a / b;
}

int main()
{

	int a;
	int b;
	char choice;
	while (true)
	{
		
		cout << "a: ";
		cin >> a;

				cout << "b: ";
			cin >> b;

			cout << "+-*/";
			cin >> choice;


			switch (choice)
			{
			case '+':
				cout << MathAdd(a, b) << endl;
				break;
			case '-':
				cout << MathSub(a, b) << endl;
				break;
			case '*':
				cout << MathMul(a, b) << endl;
				break;
			case '/':
				cout << MathDiv(a, b) << endl;
				break;
			case 'Q':
				exit(0);
			}
		system("pause");
		system("cls");
	}


	

}