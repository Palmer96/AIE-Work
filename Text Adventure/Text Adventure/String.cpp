#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

String::String(const char a_input[])
{
	int i;
	for (i = 0; a_input[i] != 0; i++){}			// size of input


	m_str = new char[i + 1];					// string size of input, +1 for NULL terminator

	for (int j = 0; j < i; j++)					// change m_str to input
	{
		m_str[j] = a_input[j];
	}

	m_str[i] = 0;								// last character = NULL
}
String::~String()
{
	delete[] m_str;
}

void String::Resize(const char a_input[])
{
	int i;
	for (i = 0; a_input[i] != 0; i++){}			// size of input

	m_str = new char[i + 1];					// string size of input, +1 for NULL terminator
	for (int j = 0; j < i; j++)					// change m_str to input
	{
		m_str[j] = a_input[j];
	}
	m_str[i] = 0;								// last character = NULL
}


// -------------------------------------------------------------------------------- Length() 
int String::Length()
{
	int i;
	for (i = 0; m_str[i] != NULL; i++)			// count until m_str reaches NULL
	{
	}
	return i;									// return the count
}

int String::Length(char str[])
{
	int i;
	for (i = 0; str[i] != NULL; i++)			// count until m_str reaches NULL
	{
	}
	return i;									// return the count
}
// --------------------------------------------------------------------------- CharacterAt() 
char String::CharacterAt(int Index)
{
	for (int i = 0; i <= Length(); i++)			// loop until end of m_str
	{
		if (i == Index)							// check if i is equal to the given number
		{
			return m_str[Index - 1];			// return the character in the m_str array at the i position
		}
	}
	return '0';									// if they is nothing at the given position then return 0
}
// ------------------------------------------------------------------------------- EqualTo() 
bool String::EqualTo(char str[])
{
	if (strcmp(m_str, str) == 0)				// string compare m_str and input
		return true;							// if m_str and input are the same return true
	else
		return false;							// else return false
}
// -------------------------------------------------------------------------------- Append() 
void String::Append(char str[])
{
	char* temp = new char[Length(str) + Length() + 1];		// create a temp array the size of the current length + the input being added

	for (int i = 0; i <= Length(); i++)			// loop until end of m_str
	{
		temp[i] = m_str[i];						// make the temp array = m_str
	}
	for (int i = 0; i <= Length(str); i++)		// loop until end of input
	{
		temp[i + Length()] = str[i];			// add the input to the end of the temp
	}
	Resize(temp);								// function to make m_str = temp
	delete temp;
}
//-------------------------------------------------------------------------------- Prepend() 
void String::Prepend(char str[])			// change
{
	char* temp = new char[Length(str) + Length() + 1];		// create a temp array the size of the current length + the string being added

	for (int i = 0; i <= Length(str); i++)		// loop until end of m_str
	{
		temp[i] = str[i];						// make the temp array = m_str
	}
	for (int i = 0; i <= Length(); i++)			// loop until end of input
	{
		temp[i + Length(str)] = m_str[i];		// add the input to the end of the temp
	}
	Resize(temp);								// function to make m_str = temp
	delete temp;
}
// ---------------------------------------------------------------------------------- CStr()
const char* String::CStr()
{
	return m_str;								// self explanitory
}
// ------------------------------------------------------------------------------- ToLower()
void String::ToLower()
{
	for (int i = 0; i <= Length(); i++)			// loop until end of m_str
	{
		if (m_str[i] > 64 && m_str[i] < 91)		// check if m_str[i] is uppercase
		{
			m_str[i] += 32;						// make it lowercase
		}
	}

}
// ------------------------------------------------------------------------------- ToUpper()
void String::ToUpper()
{
	for (int i = 0; i <= Length(); i++)			// loop until end of m_str
	{
		if (m_str[i] > 96 && m_str[i] < 123)	// check if m_str[i] is lowercase
		{
			m_str[i] -= 32;						// make it uppercase
		}
	}
}
// ---------------------------------------------------------------------------------- Find()
int String::Find(char findString[])
{
	for (int i = 0; i <= Length(); i++)			// loop until end of m_str
	{
		int j;
		for (j = 0; m_str[i + j] == findString[j]; j++)
		{
			if (findString[j] == '\0')			// check if found a single character
			{
				break;
			}
		}
		if (j == Length(findString))			// check if j has reached findString
		{
			return i;
		}
	}
	return -1;
}
// ---------------------------------------------------------------------------------- Find()
int String::Find(int startIndex, char findString[])
{

	for (int i = startIndex; i <= Length(); i++)	// loop until end of m_str, starting at startIndex
	{
		int j;
		for (j = 0; m_str[i + j] == findString[j]; j++)
		{
			if (findString[j] == '\0')			// check if found a single character
			{
				break;
			}
		}
		if (j == Length(findString))			// check if j has reached findString
		{
			return i;
		}
	}
	return -1;
}
// ------------------------------------------------------------------------------- Replace()
void String::Replace(char findString[], char replaceString[])
{
	while (Find(findString) != -1)				// run and loop if able to find string
	{

		int fLocation = Find(findString);		// set variables
		int rSize = strlen(replaceString);
		int fSize = strlen(findString);
		int currentLoc = 0;

		int tempLength = Length() + (rSize - fSize) + 1;	// create a temp large enough for end result
		char* temp = new char[tempLength];


		if (rSize != fSize)						// check if the replace string and find string are the same 
		{

			int i = 0;
			for (i = 0; i < fLocation; i++)		// insert m_str into temp until i = findString location
			{
				temp[i] = m_str[i];
			}
			int j = 0;
			for (j = 0; j < rSize; j++)			// insert replace string into temp
			{
				temp[j + i] = replaceString[j];
			}
			i += j - 1;							// add j to i then take 1 to account for position
			for (; i < tempLength; i++)			// put the rest of m_str into temp
			{
				temp[i + 1] = m_str[i];
			}


			Resize(temp);						// function to make m_str = temp
			delete temp;
		}
		else									// if the replace string and find string are the same 
		{
			int j = fLocation;
			for (int i = 0; i < fSize; i++)
			{
				m_str[j] = replaceString[i];	// replace m_str at find string with replace string
				j++;
			}
		}

	}
}
// ----------------------------------------------------------------------- ReadFromConsole()

void String::ReadFromConsole()
{
	cout << "Read From Console: ";				// ask user for input
	cin >> m_str;								// m_str = user input
}
// ------------------------------------------------------------------------ WriteToConsole()
void String::WriteToConsole()
{
	cout << "Write To Console: " << m_str << endl;		// print m_str to console 
}

void String::Read()
{
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
}

