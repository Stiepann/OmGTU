// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int
main()
{
	int number;
	char input[2000];
	cin >> input >> number;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] >= 'A'&&input[i] <= 'Z')
		{
			input[i] = input[i] + number;
		}
		else if (input[i] >= 'a'&&input[i] <= 'z')
		{
			input[i] = input[i] + number;
		}
		cout << input[i];
	}
	return 0;
}