#ifndef _STRING_H
#define _STRING_H

class String
{
public:
	String(const char a_input[]);				// constructor

	int Length();													//  1
	char CharacterAt(int Index);									//  2
	bool EqualTo(char str[]);										//  3
	void Append(char str[]);										//  4
	void Prepend(char str[]);										//  5
	const char* CStr();												//  6
	void ToLower();													//  7
	void ToUpper();													//  8
	int Find(char findString[]);									//  9
	int Find(int startIndex, char findString[]);					//  10
	void Replace(char findString[], char replaceString[]);			//  11
	void ReadFromConsole();											//  12
	void WriteToConsole();											//  13

	void Resize(const char a_input[]);			// function to resize and change m_str to the input
	int Length(char str[]);						// overload Length() function to take input
	void Read();								// function to read from text file

	~String();									// destructor
private:
	char* m_str = nullptr;						// string
};

#endif //_STRING_H