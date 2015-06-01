#include <iostream>
#include <fstream>
#include <time.h>
#include "Header.h"
using namespace std;

int main()
{
	{
		String string("Mississippi");

		// ------------------------------------------------------------ Variables
		char cInput[] = "Pear";
		char cInput2[] = "SI";
		char cInput3[] = "get";
		int iNumInput = 8;
		float count = 0.0f;
		float percentage = 0;

		// ------------------------------------------------------------ File
		ofstream Text;
		Text.open("Test.txt", ios::app);		// open and append to file

		// ------------------------------------------------------------ Time
		time_t now;
		struct tm timeinfo;
		time(&now);
		localtime_s(&timeinfo, &now);

		char st[80];
		strftime(st, 80, "Date: %a %d %b %Y     Time: %I:%M:%S %p", &timeinfo);


		// ------------------------------------------------------------ File Heading
		Text << "____________________________________________";
		Text << endl << st << endl;									// showing time
		Text << "____________________________________________" << endl;
		Text << "Test        Function            Status" << endl;
		Text << "--------------------------------------------" << endl;

		// -------------------------------------------------------------------------------- Length() 
		if (string.Length() == 11)
		{
			Text << "Test 1      Length              Success" << endl;
			count++;
		}
		else
			Text << "Test 1      Length              Failed" << endl;
		// --------------------------------------------------------------------------- CharacterAt() 
		if (string.CharacterAt(5) == 'i')
		{
			Text << "Test 2      CharacterAt         Success" << endl;
			count++;
		}
		else
			Text << "Test 2      CharacterAt         Failed" << endl;
		// ------------------------------------------------------------------------------- EqualTo() 
		if (string.EqualTo(cInput) == false)
		{
			Text << "Test 3      EqualTo             Success" << endl;
			count++;
		}
		else
			Text << "Test 3      EqualTo             Failed" << endl;
		// -------------------------------------------------------------------------------- Append() 
		string.Append(cInput);
		if (string.EqualTo("MississippiPear") == true)
		{
			Text << "Test 4      Append              Success" << endl;
			count++;
		}
		else
			Text << "Test 4      Append              Failed" << endl;
		//-------------------------------------------------------------------------------- Prepend() 
		string.Prepend(cInput);
		if (string.EqualTo("PearMississippiPear") == true)
		{
			Text << "Test 5      Preppend            Success" << endl;
			count++;
		}
		else
			Text << "Test 5      Preppend            Failed" << endl;
		// ---------------------------------------------------------------------------------- CStr()
		if (string.EqualTo("PearMississippiPear") == true)
		{
			Text << "Test 6      CStr                Success" << endl;
			count++;
		}
		else
			Text << "Test 6      CStr                Failed" << endl;
		// ------------------------------------------------------------------------------- ToLower()
		string.ToLower();
		if (string.EqualTo("pearmississippipear") == true)
		{
			Text << "Test 7      ToLower             Success" << endl;
			count++;
		}
		else
			Text << "Test 7      ToLower             Failed" << endl;
		// ------------------------------------------------------------------------------- ToUpper()
		string.ToUpper();
		if (string.EqualTo("PEARMISSISSIPPIPEAR") == true)
		{
			Text << "Test 8      ToUpper             Success" << endl;
			count++;
		}
		else
			Text << "Test 8      ToUpper             Failed" << endl;
		// ---------------------------------------------------------------------------------- Find()
		if (string.Find(cInput2) == 7)
		{
			Text << "Test 9      Find                Success" << endl;
			count++;
		}
		else
			Text << "Test 9      Find                Failed" << endl;
		// ---------------------------------------------------------------------------------- Find()
		if (string.Find(iNumInput, cInput2) == 10)
		{
			Text << "Test 10     Find                Success" << endl;
			count++;
		}
		else
			Text << "Test 10     Find                Failed" << endl;
		// ------------------------------------------------------------------------------- Replace()
		string.Replace(cInput2, cInput3);
		if (string.EqualTo("PEARMISgetSgetPPIPEAR") == true)
		{
			Text << "Test 11     Replace             Success" << endl;
			count++;
		}
		else
			Text << "Test 11     Replace             Failed" << endl;
		// ----------------------------------------------------------------------- ReadFromConsole()
		string.ReadFromConsole();
		if (true)
		{
			Text << "Test 12     ReadFromConsole     Success" << endl;
			count++;
		}
		else
			Text << "Test 12     ReadFromConsole     Failed" << endl;
		// ------------------------------------------------------------------------ WriteToConsole()
		string.WriteToConsole();
		if (true)
		{
			Text << "Test 13     WriteToConsole      Success" << endl;
			count++;
		}
		else
			Text << "Test 13     WriteToConsole      Failed" << endl;

		// ------------------------------------------------------------ File Heading
		float Percent = (count / 13.0f) * 100.0f;
		Text << "--------------------------------------------" << endl;
		Text << " Percent Successful: " << Percent << " %" << endl;
		Text << "____________________________________________" << endl << endl << endl;

		system("pause");

		// ------------------------------------------------------------ Read from file
		fstream inputFile;
		inputFile.open("Test.txt", ios::in);		// open file to read from

		if (inputFile.is_open())					// if file is open
		{
			char buffer[64];
			while (inputFile.getline(buffer, 64))	// loop while file has content to show
			{
				cout << buffer << endl;				// shw content of file
			}
		}
		inputFile.close();							// close file
		Text.close();		// close file

		system("pause");

	}
	_CrtDumpMemoryLeaks();
}