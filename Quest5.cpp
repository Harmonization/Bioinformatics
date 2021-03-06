#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Go(string str)
{
	if (str == "ATG") return("M");
	if ((str == "ATA") || (str == "ATC") || (str == "ATT")) return("I");
	if ((str == "AGG") || (str == "AGA")) return("R");
	if ((str == "AGC") || (str == "AGT")) return("S");
	if ((str == "ACG") || (str == "ACC") || (str == "ACA") || (str == "ACT")) return("T");
	if ((str == "AAG") || (str == "AAA")) return("K");
	if ((str == "AAC") || (str == "AAT")) return("N");
	if ((str == "TTG") || (str == "TTA")) return("L");
	if ((str == "TTC") || (str == "TTT")) return("F");
	if ((str == "TGG")) return("W");
	if ((str == "TGC") || (str == "TGT")) return("C");
	if ((str == "TCC") || (str == "TCT") || (str == "TCA") || (str == "TCG")) return("S");
	if ((str == "TAC") || (str == "TAT")) return("Y");
	if ((str == "CAT") || (str == "CAC")) return("H");
	if ((str == "CAA") || (str == "CAG")) return("Q");
	if ((str == "CCG") || (str == "CCA") || (str == "CCC") || (str == "CCT")) return("P");
	if ((str == "CGG") || (str == "CGA") || (str == "CGC") || (str == "CGT")) return("R");
	if ((str == "CTG") || (str == "CTA") || (str == "CTC") || (str == "CTT")) return("L");
	if ((str == "GAT") || (str == "GAC")) return("D");
	if ((str == "GAA") || (str == "GAG")) return("E");
	if ((str == "GCG") || (str == "GCA") || (str == "GCC") || (str == "GCT")) return("A");
	if ((str == "GGG") || (str == "GGA") || (str == "GGC") || (str == "GGT")) return("G");
	if ((str == "GTG") || (str == "GTA") || (str == "GTC") || (str == "GTT")) return("V");
	if ((str == "TGA") || (str == "TAA") || (str == "TAG")) return "";
}
string demoMulty(string str, string Peptide)
{
	int k = Peptide.length() * 3;
		string s = "";
		for (int i = 0; i < k; i = i + 3)
		{
			s += Go(str.substr(i, 3));
		}
		return s;
}
vector <string> Rage(string DNA, string Peptide)
{
	int k = Peptide.length() * 3;
	vector <string> result;
	for (int i = 0; i < DNA.length() - k + 1; i++)
		result.push_back(DNA.substr(i, k));
	return result;
}
string Back(string str)
{
	string s = "";

	for (int j = str.length() - 1; j >= 0; j--)
	{
		if (str.substr(j, 1) == "A") s += "T";
		else if (str.substr(j, 1) == "T") s += "A";
		else if (str.substr(j, 1) == "G") s += "C";
		else if (str.substr(j, 1) == "C") s += "G";
	}
	return s;
}
vector <string> multyRage(vector <string> DNA, string Peptide)
{
	int k = Peptide.length() * 3;
	vector <string> result;
	for (int i = 0; i < DNA.size(); i++)
	{
		string str = demoMulty(DNA[i], Peptide);
		if (str == Peptide) result.push_back(DNA[i]);
		string str2 = demoMulty(Back(DNA[i]), Peptide);
		if (str2 == Peptide) result.push_back(DNA[i]);
	}
	return result;
}
void print(vector <string> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
}
int main()
{
    string dna;
    cin >> dna;
	string Peptide;
    cin >> Peptide;
	vector <string> DNA = Rage(dna, Peptide);
	print(multyRage(DNA, Peptide));
	getchar();
	return 0;
}
