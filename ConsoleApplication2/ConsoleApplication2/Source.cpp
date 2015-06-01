#include <iostream>
#include "Header.h"





int main()
{

	int a = 3;
	int b;
	int val;
	std::cout << "b: ";
	std::cin >> b;

	std::cout << "Add: " << Add(a, b) << std::endl;
	std::cout << "Min: " << Min(a, b) << std::endl;
	std::cout << "Max: " << Max(a, b) << std::endl;
	std::cout << "Enter a Value: ";
	std::cin >> val;
	std::cout << "Clamp: " << Clamp(Min(a,b), Max(a,b), val) << std::endl;

	char A[] = { 'A' };
	std::cin >> A;
	char E[] = { 'E' };
	std::cin >> E;




	std::cout << "Min (char): " << Min(A, E) << std::endl;
	std::cout << "Max (char): " << Max(A, E) << std::endl;


}