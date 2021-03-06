#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
using namespace std;

void delStr(std::string arif, std::string ZnakRazdel, std::string *rezt, int &ki)
{
	std::string Stok = arif + " ";
	int Cn = Stok.length();
	int m = ZnakRazdel.length();
	ki = 0;

	for (int i = 0; i < Cn; i++)
	{
		int L = ZnakRazdel.find(Stok[i]);

		if ((L > m) || (L < 0))
		{
			rezt[ki] = rezt[ki] + Stok[i];
		}
		else
			if (Stok[i] == ZnakRazdel[0])
			{
				if (rezt[ki] != "")
				{
					rezt[++ki] = "";
				}
			}
			else
			{
				if (rezt[ki] != "")
				{
					ki++;
				}

				rezt[ki] = Stok[i];
				rezt[++ki] = "";
			}
	}
}
vector <string> Vec(string *rezt)
{
	vector <string> result;
	for (int i = 0; i < rezt->size(); i++)
		if (rezt[i] != "")
			result.push_back(rezt[i]);
	return result;
}
template <class T>
void print(vector <T> A)
{
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << endl;
}
vector <int> StrInt(vector <string> A)
{
	vector <int> result;
	for (int i = 0; i < A.size(); i++)
		result.push_back(atoi(A[i].c_str()));
	return result;
}
int Sum(vector <int> A)
{
	int result = 0;
	for (int i = 0; i < A.size(); i++)
		result += A[i];
	return result;
}
int Combo(string arif)
{
	int ki = 0;
	string rezt[100];
	delStr(arif, "-", rezt, ki);
	vector <string> A = Vec(rezt);
	vector <int> B = StrInt(A);
	return Sum(B);
}
bool find(int sp, vector <int> Spectrum)
{
	for (int i = 0; i < Spectrum.size(); i++)
	{
		if (sp == Spectrum[i]) return true;
	}
	return false;
}
bool Harmonized(vector <int> sp, vector <int> Spectrum)
{
	for (int i = 0; i < sp.size(); i++)
		if (!find(sp[i], Spectrum)) return false;
	return true;
}
bool Harmonized1(vector <int> sp, vector <int> Spectrum)
{
	vector <int> Spec = Spectrum;
	vector <int> Sp = sp;
	for (int j = 0; j < Spec.size(); )
	{
		int k = Spec.size();
		for (int i = 0; i < Sp.size(); )
		{
			if (Sp[i] == Spec[j])
			{
				Spec.erase(Spec.begin() + j);
				Sp.erase(Sp.begin() + i);
				break;
			}
			else i++;
		}
		if (k == Spec.size())
			j++;
	}
	if (Sp.size() == 0)
		return true;
	return false;
}
//////

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
	string doublePeptide = Peptide;
	vector <string> pup;
	for (int i = 1; i < Peptide.length(); i++)
	{
		for (int j = 0; j < Peptide.length() - i + 1; j++)
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


///////

string Clear(string Mass)
{
	string Mass1 = Mass;
	int n = Mass.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 2; j < n; j++)
		{
			if (Mass.substr(i, 3) == Mass.substr(j, 3))
			{
				Mass1 = "";
			}
		}
	}
	return Mass;
}
bool Search(string str, string k)
{
	bool b = false;
	for (int i = 0; i < str.length(); i++)
	{
		if (k == str.substr(i, k.length())) b = true;
	}
	return b;
}
bool SearchMap(map <string, int> str, string k)
{
	bool b = false;
	map <string, int> ::iterator s;
	for (s = str.begin(); s != str.end(); s++)
	{
		if (s->first == k) b = true;
	}
	return b;
}
map <string, string> Bunny(vector <int> Spectre)
{
	map <string, string> result;
	map <string, string> ::iterator it;
	it = result.begin();

	map <string, string> res;
	map <string, string> ::iterator r;
	r = res.begin();

	map <string, string> Mass;
	Mass["113"] = "L";
	Mass["129"] = "E";
	Mass["128"] = "K";
	Mass["114"] = "N";
	Mass["71"] = "A";
	Mass["87"] = "S";
	Mass["97"] = "P";
	Mass["99"] = "V";
	Mass["101"] = "T";
	Mass["103"] = "C";
	Mass["115"] = "D";
	Mass["131"] = "M";
	Mass["137"] = "H";
	Mass["147"] = "F";
	Mass["156"] = "R";
	Mass["163"] = "Y";
	Mass["186"] = "W";
	Mass["57"] = "G";
	map <string, string> ::iterator m;

	for (m = Mass.begin(); m != Mass.end(); m++) //первый шаг
	{
		for (int j = 0; j < Spectre.size(); j++)
		{
			if (atoi(m->first.c_str()) == Spectre[j]) result[m->first] = m->second;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (m = Mass.begin(); m != Mass.end(); m++)
		{
			for (it = result.begin(); it != result.end(); it++)
			{
				int k = Combo(it->first + "-" + m->first);
				if (find(k, Spectre))
				{
					vector <int> sp = Falcon(it->second + m->second);
					if (Harmonized1(sp, Spectre))
					{
						res[it->first + "-" + m->first] = it->second + m->second;
					}
				}
			}
		}
		if (res.size() == 0)
		{
			break;
		}
		result = res;
		res.clear();
	}


	return result;

}
int main()
{
	vector <int> Spectre;
	int i = 0;
	while (i < 10000) {
		int k1;
		cin >> k1;

		if (cin.fail())
			break;

		Spectre.push_back(k1);
		i++;
	}
	map <string, string> result = Bunny(Spectre);
	map <string, string> ::iterator it;
	it = result.begin();
	for (; it != result.end(); it++)
	{
		cout << it->first + " ";
	}
	getchar();
	return 0;
}