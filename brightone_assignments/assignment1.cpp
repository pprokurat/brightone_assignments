#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

//#define byte char

using namespace std;


int main()
{
		string fileName;
		cout << "Podaj nazwe pliku: ";
		cin >> fileName;
		cout << endl;

		string fileContent;
		string line;
		ifstream inFile;
		inFile.open(fileName);
		while (!inFile.eof())
		{
			getline(inFile, line);
			fileContent += line + "\n";
		}
		inFile.close();

		cout << fileContent << endl;

		char hexDigits[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		string filteredContent;
		

		for (char& c : fileContent)
		{
			for (int i = 0; i < (sizeof(hexDigits) / sizeof(*hexDigits)); i++)
			{
				if (c == hexDigits[i])
				{
					filteredContent += c;
					break;
				}					
			}
		}

		cout << filteredContent << endl;

		const int outputSize = filteredContent.length();
			
		//byte * byteArray = new byte[outputSize / 2 + 1];
		string * byteArray = new string[outputSize / 2 + 1];

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << byteArray[i] << " ";
		}
		cout << endl;

		int i = 0, j = 0;
		for (char& c : filteredContent)
		{	
			
			byteArray[i] += c;

			if (j % 2 != 0)
			{				
				i++;				
			}

			j++;

			if (j == outputSize)
				break;
		}

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{ 
			cout << byteArray[i] << " ";
		}
		cout << endl;

		string * binArray = new string[outputSize / 2 + 1];

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			for (char& c : byteArray[i])
			{
				switch (c)
				{
				case '0': binArray[i] += "0000";		
					break;
				case '1': binArray[i] += "0001";
					break;
				case '2': binArray[i] += "0010";
					break;
				case '3': binArray[i] += "0011";
					break;
				case '4': binArray[i] += "0100";
					break;
				case '5': binArray[i] += "0101";
					break;
				case '6': binArray[i] += "0110";
					break;
				case '7': binArray[i] += "0111";
					break;
				case '8': binArray[i] += "1000";
					break;
				case '9': binArray[i] += "1001";
					break;
				case 'A': binArray[i] += "1010";
					break;
				case 'B': binArray[i] += "1011";
					break;
				case 'C': binArray[i] += "1100";
					break;
				case 'D': binArray[i] += "1101";
					break;
				case 'E': binArray[i] += "1110";
					break;
				case 'F': binArray[i] += "1111";
					break;
				}				
			}
			cout << " ";
		}
		cout << endl;

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArray[i] << " ";
		}
		cout << endl;
		
	
	//delete[] byteArray;

	system("pause");
    return 0;
}

