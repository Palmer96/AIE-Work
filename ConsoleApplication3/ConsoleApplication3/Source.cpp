#include <iostream>



int main()
{
	char asd[] = "Apple";
	int count = 0;

	for (int i = 0; asd[i] != NULL; i++)
	{
		count++;
	}

	std::cout << count << std::endl;


	system("pause");
}