#include "stdafx.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
	int casesNumber;
	cin >> casesNumber;

	int ** elementsArray = new int * [casesNumber];
	
	int caseElementsNumber, element;

	for (int i = 0; i < casesNumber; i++)
	{
		cin >> caseElementsNumber;
		elementsArray[i] = new int[caseElementsNumber];

		for (int j = 0; j < caseElementsNumber; j++)
		{
			cin >> element;
			elementsArray[i][j] = element;
		}

	}

	for (int i = 0; i < casesNumber; i++)
	{
		for (int j = 0; j <= (sizeof(elementsArray[i]) / sizeof(int)); j++)
		{
			cout << elementsArray[i][j] << " ";
		}
		cout << endl;
	}


	

	for (int i = 0; i < casesNumber; i++)
		delete[] elementsArray[i];

	delete[] elementsArray;

	system("pause");
    return 0;
}

