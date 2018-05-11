#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <climits>
#include <algorithm>

using namespace std;

size_t popcount(string n) {
	std::bitset<sizeof(string) * CHAR_BIT> b(n);
	return b.count();
}

struct greater
{
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
		//wybór pliku
		string fileName;
		cout << "Podaj nazwe pliku: ";
		cin >> fileName;
		//cout << endl;

		//odczyt pliku
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

		//wypisanie zawartości
		//cout << fileContent << endl;

		//odfiltrowanie cyfr spoza zakresu hex
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

		//wypisanie zawartości po odfiltrowaniu
		//cout << filteredContent << endl;

		//pogrupowanie w bajty
		const int outputSize = filteredContent.length();
			
		string * byteArray = new string[outputSize / 2 + 1];
		
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

		//wypisanie grup
		/*for (int i = 0; i < outputSize / 2 + 1; i++)
		{ 
			cout << byteArray[i] << " ";
		}
		cout << endl;*/

		//zamiana na bin
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

		//wypisanie w bin
		/*for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArray[i] << " ";
		}
		cout << endl;*/

		//podział na elementy o parzystej i nieparzystej ilości jedynek
		string * binArrayEven = new string[outputSize / 2 + 1];

		string * binArrayOdd = new string[outputSize / 2 + 1];

		for (int i = 0, k = 0, l = 0; i < outputSize / 2 + 1; i++)
		{
			//wypisanie ilości jedynek
			//cout << popcount(binArray[i]) << " ";

			if (popcount(binArray[i]) % 2 == 0)
			{
				binArrayEven[k] += binArray[i];
				k++;
			}
			else
			{
				binArrayOdd[l] += binArray[i];
				l++;
			}
		}
		//cout << endl;

		//wypisanie elementów "parzystych"
		/*for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArrayEven[i] << " ";
		}
		cout << endl;*/

		//wypisanie elementów "nieparzystych"
		/*for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArrayOdd[i] << " ";
		}
		cout << endl;*/

		//sortowanie el. "parzystych" w kolejności rosnącej i ich wypisanie
		sort(binArrayEven, binArrayEven + (outputSize / 2 + 1));

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArrayEven[i] << " ";
		}
		cout << endl;

		//sortowanie el. "parzystych" w kolejności malejącej i ich wypisanie
		sort(binArrayOdd, binArrayOdd + (outputSize / 2 + 1), greater());

		for (int i = 0; i < outputSize / 2 + 1; i++)
		{
			cout << binArrayOdd[i] << " ";
		}
		cout << endl;
		

	system("pause");
    return 0;
}

