#include <iostream>
#include <string>
using namespace std;

string Mouse(string Codone)
{
	for (int i = 0; i < Codone.length(); i++)
	{
		if (Codone == "AUG") return "M";
		else if ((Codone == "CAU") || (Codone == "CAC")) return "H";
		else if ((Codone == "CAA") || (Codone == "CAG")) return "Q";
		else if ((Codone == "CCA") || (Codone == "CCG") || (Codone == "CCU") || (Codone == "CCC")) return "P";
		else if ((Codone == "CGA") || (Codone == "CGG") || (Codone == "CGU") || (Codone == "CGC")) return "R";
		else if ((Codone == "CUA") || (Codone == "CUG") || (Codone == "CUU") || (Codone == "CUC")) return "L";
		else if ((Codone == "GAU") || (Codone == "GAC")) return "D";
		else if ((Codone == "GAA") || (Codone == "GAG")) return "E";
		else if ((Codone == "GCA") || (Codone == "GCG") || (Codone == "GCU") || (Codone == "GCC")) return "A";
		else if ((Codone == "GGA") || (Codone == "GGG") || (Codone == "GGU") || (Codone == "GGC")) return "G";
		else if ((Codone == "GUA") || (Codone == "GUG") || (Codone == "GUU") || (Codone == "GUC")) return "V";
		else if ((Codone == "UAU") || (Codone == "UAC")) return "Y";
		else if ((Codone == "UCA") || (Codone == "UCG") || (Codone == "UCU") || (Codone == "UCC")) return "S";
		else if ((Codone == "UGU") || (Codone == "UGC")) return "C";
		else if (Codone == "UGG") return "W";
		else if ((Codone == "UUU") || (Codone == "UUC")) return "F";
		else if ((Codone == "UUA") || (Codone == "UUG")) return "L";
		else if ((Codone == "AAU") || (Codone == "AAC")) return "N";
		else if ((Codone == "AAG") || (Codone == "AAA")) return "K";
		else if ((Codone == "ACA") || (Codone == "ACG") || (Codone == "ACU") || (Codone == "ACC")) return "T";
		else if ((Codone == "AGU") || (Codone == "AGC")) return "S";
		else if ((Codone == "AGA") || (Codone == "AGG")) return "R";
		else if ((Codone == "AUU") || (Codone == "AUC") || (Codone == "AUA")) return "I";
		else if (Codone == "UGA") return "";
		else if ((Codone == "UAG") || (Codone == "UAA")) return "";
	}
}

string Frog(string multyCodone)
{
	string result = "";
	for (int i = 0; i < multyCodone.length(); i = i + 3)
	{
		result = result + Mouse(multyCodone.substr(i, 3));
	}
	return result;
}

int main()
{
	string multyCodone;
	cin >> multyCodone;
	string result = Frog(multyCodone);
	cout << result;
	getchar();
	return 0;
}