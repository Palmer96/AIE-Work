#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>


int main()
{
	int s;
	int m;
	int h;
	int choice;
	int click = 0;
	bool a;

	
	while (true)
	{
		a = true;
std::cout << "1 = Clock, 2 = Stopwatch, 3 = Timer" << std::endl;
	std::cin >> choice;
	system("cls");

		switch (choice)
		{
		case 1:
			char st[80];
			char at[80];
			while (a)
			{
				time_t now;
				struct tm timeinfo;
				time(&now);
				localtime_s(&timeinfo, &now);

				//std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

				std::cout << "     _____________________________________________" << std::endl;
				std::cout << "    |                                             |" << std::endl;
				strftime(st, 80, "    | Date: %a %d %b %Y     Time: %I:%M:%S %p |", &timeinfo);
				std::cout << st << std::endl;
				std::cout << "    |_____________________________________________|" << std::endl;

				Sleep(1000);

				if (GetAsyncKeyState(VK_SPACE) & 0x8000)
				{
					Sleep(2000);
					system("pause");
					system("cls");
					a = false;
					//break;
				}

				system("cls");

			}
			break;
		case 2:
			h = 0;
			m = 0;
			s = 0;

			system("cls");
			//std::cout << std::endl;
			std::cout << "                          _______" << std::endl;
			std::cout << "                         |       |" << std::endl;
			std::cout << "                           " << h << ":" << m << ":" << s << std::endl;
			std::cout << "                         |_______|" << std::endl;
			system("pause");

			while (true)
			{

				
s++;
				system("cls");
				std::cout << "                          _______" << std::endl;
				std::cout << "                         |       |" << std::endl;
				std::cout << "                           " << h << ":" << m << ":" << s << std::endl;
				std::cout << "                         |_______|" << std::endl;
				Sleep(1000);
				

				if (s == 60)
				{
					s = 0;
					m++;
				}
				if (m == 60)
				{
					m = 0;
					h++;
				}
				
				if (GetAsyncKeyState(VK_SPACE) & 0x8000)
				{
					Sleep(2000);
					getch();
					std::cout << std::endl << "The time stopped at: " << h << " Hours, " << m << " Minutes and " << s << " Seconds" << std::endl;
					system("pause");
					system("cls");
					break;
				}
			}
			break;
		case 3:
			std::cout << "Hours: ";
			std::cin >> h;
			std::cout << "Minutes: ";
			std::cin >> m;
			int q = h;
			int e = m;
			s = 00;

			system("cls");
			std::cout << std::endl << std::endl;
			std::cout << "                          ________" << std::endl;
			std::cout << "                         |        |" << std::endl;
			std::cout << "                            " << h << ":" << m << ":" << s << std::endl;
			std::cout << "                         |________|" << std::endl;
			system("pause");
			system("cls");

			while (true)
			{
				std::cout << std::endl << "                     Time until break" << std::endl;
				std::cout << "                          ________" << std::endl;
				std::cout << "                         |        |" << std::endl;
				std::cout << "                           " << h << ":" << m << ":" << s << std::endl;
				std::cout << "                         |________|" << std::endl;

				s--;


				if (s <= 0 && m == 0)
				{
					s = 0;
				}
				else if (s <= 0 && m > 0)
				{
					s = 59;
					m--;
				}
				if (m <= 0 && h == 0)
				{
					m = 0;
				}
				else if (m < 0 && h > 0)
				{
					m = 59;
					h--;
				}
				if (s == 0 && m == 0 && h > 0)
				{
					m = 59;
					h--;
				}

				if (h == 0 && m == 0 && s == 0)
				{
					system("cls");

					std::cout << "                          _______" << std::endl;
					std::cout << "                         |       |" << std::endl;
					std::cout << "                         | 0:0:0 |" << std::endl;
					std::cout << "                         |_______|" << std::endl;
					std::cout << std::endl << "Done" << std::endl << std::endl;
					std::cout << q << " Hours and " << e << " Minutes has passed" << std::endl;
					std::cout << "                                                           " << std::endl;
					std::cout << "  /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\   " << std::endl;
					std::cout << "  \\                                  /     " << std::endl;
					std::cout << "  /              BREAK !!!!          \\    " << std::endl;
					std::cout << "  \\              TIME !!!!           /      " << std::endl;
					std::cout << "  /                                  \\      " << std::endl;
					std::cout << "  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/                        _______                          " << std::endl;
					system("pause");
					system("cls");
					break;
				}
				Sleep(1000);
				system("cls");
			}
			break;
		}
	}
}