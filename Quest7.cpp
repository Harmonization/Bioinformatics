#include <iostream>
#include <string>
#include <vector>
using namespace std;

string clear(string Peptide) // уберем пробелы, если они есть
{
	for (int i = 0; i < Peptide.length(); i++)
	{
		if (Peptide.substr(i, 1) == " ") Peptide.erase(i, 1);
	}
	return Peptide;
}

int mass(string Peptide) // преобразование элемента в его массу 
{
	Peptide = clear(Peptide);
	if (Peptide == "L") return 113;
	else if (Peptide == "E") return 129;
	else if (Peptide == "Q") return 128;
	else if (Peptide == "N") return 114;
	else if (Peptide == "A") return 71;
	else if (Peptide == "S") return 87;
	else if (Peptide == "P") return 97;
	else if (Peptide == "V") return 99;
	else if (Peptide == "T") return 101;
	else if (Peptide == "C") return 103;
	else if (Peptide == "I") return 113;
	else if (Peptide == "D") return 115;
	else if (Peptide == "K") return 128;
	else if (Peptide == "M") return 131;
	else if (Peptide == "H") return 137;
	else if (Peptide == "F") return 147;
	else if (Peptide == "R") return 156;
	else if (Peptide == "Y") return 163;
	else if (Peptide == "W") return 186;
	else if (Peptide == "G") return 57;
	else return 0;
}

int multiple(string Peptide) // преобразование строки в сумму масс элементов
{
	Peptide = clear(Peptide);
	int result = 0;
	for (int i = 0; i < Peptide.length(); i++)
	{
		result += mass(Peptide.substr(i, 1));
	}
	return result;
}

vector <string> Wolf(string Peptide) // преобразование пептида в возможные разложения 
{
	Peptide = clear(Peptide);
	string doublePeptide = Peptide + Peptide;
	vector <string> pup;
	for (int i = 1; i < Peptide.length(); i++)
	{
		for (int j = 0; j < Peptide.length(); j++)
		{
			pup.push_back(doublePeptide.substr(j, i));
		}
	}
	pup.push_back(Peptide);
	return pup;
}

vector <int> Falcon(string Peptide) // преобразование пептида в массы возможных разложений 
{
	Peptide = clear(Peptide);
	vector <int> eyas;
	eyas.push_back(0);
	for (int i = 0; i < Wolf(Peptide).size(); i++)
	{
		eyas.push_back(multiple(Wolf(Peptide)[i]));
	}
	for (int i = 1; i < eyas.size() - 1; i++)
	{
		for (int j = i + 1; j < eyas.size(); j++)
		{
			if (eyas[i] > eyas[j])
			{
				int go = 0;
				go = eyas[j];
				eyas[j] = eyas[i];
				eyas[i] = go;
			}
		}
	}
	return eyas;
}
int main()
{
	string bunny;
	getline(cin, bunny);
	int n = clear(bunny).length();
	for (int i = 0; i < (n * (n - 1) + 2); i++)
		cout << Falcon(bunny)[i] << " ";
	getchar();
	return 0;
}