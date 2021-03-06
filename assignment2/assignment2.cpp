#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//wprowadzenie ilości przypadków
	cout << "Input: " << endl;
	int casesNumber;
	cin >> casesNumber;

	int ** elementsArray = new int * [casesNumber];
	int * caseElementsNumberArray = new int [casesNumber];
	
	int caseElementsNumber, element;

	//wprowadzenie ilości liczb w każdym z przypadków oraz danych liczb
	for (int i = 0; i < casesNumber; i++)
	{
		cin >> caseElementsNumber;
		elementsArray[i] = new int[caseElementsNumber];
		caseElementsNumberArray[i] = caseElementsNumber;

		for (int j = 0; j < caseElementsNumber; j++)
		{
			cin >> element;
			elementsArray[i][j] = element;
		}
	}

	//wypisanie danych wejściowych na konsoli
	/*for (int i = 0; i < casesNumber; i++)
	{
		for (int j = 0; j < caseElementsNumberArray[i]; j++)
		{
			cout << elementsArray[i][j] << " ";
		}
		cout << endl;
	}*/

	//sprawdzanie stosunku sumy elementów po prawej i lewej
	cout << "\nOutput: " << endl;

	int sumLeft = 0, sumRight = 0;
	for (int i = 0; i < casesNumber; i++)
	{
		for (int j = 0; j < caseElementsNumberArray[i]; j++)
		{
			sumLeft = 0;
			sumRight = 0;
			if (j != 0)
			{
				for (int k = j - 1; k > -1; k--)
				{
					sumLeft += elementsArray[i][k];
				}
				//cout << "sum left: " << sumLeft << endl;
			}
			
			if (j != caseElementsNumberArray[i] - 1)
			{
				for (int l = j + 1; l < caseElementsNumberArray[i]; l++)
				{
					sumRight += elementsArray[i][l];
				}
				//cout << "sum right: " << sumRight << endl;
			}
			
			//wypisanie wartości wyjściowych
			if ((sumLeft == sumRight))
			{
				cout << "Yes" << endl;
				break;
			}
			
			if (j == caseElementsNumberArray[i] - 1)
			{
				cout << "No" << endl;
			}				
		}
	}

	cout << endl;

	for (int i = 0; i < casesNumber; i++)
		delete[] elementsArray[i];

	delete[] elementsArray;
	delete[] caseElementsNumberArray;

	system("pause");
    return 0;
}

