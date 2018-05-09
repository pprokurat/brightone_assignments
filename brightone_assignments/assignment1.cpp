#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

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


	system("pause");
    return 0;
}

