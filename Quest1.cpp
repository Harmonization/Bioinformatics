#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	string Genome;
	string Pattern;
	cin >> Pattern;
	cin >> Genome;
	for (int i = 0; i < (Genome.length() - Pattern.length() + 1); i++)
	{
		if (Pattern == Genome.substr(i, Pattern.length())) count++;
	}
	cout << count;
	getchar();
	return 0;
}