#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Pattern1;
	cin >> Pattern1;
	string Pattern2 = Pattern1;
	for (int i = 0; i < Pattern1.length(); i++)
	{
		if (Pattern1[i] == 'A')
		{
			Pattern2[Pattern1.length() - i - 1] = 'T';
		}
		else if (Pattern1[i] == 'C')
		{
			Pattern2[Pattern1.length() - i - 1] = 'G';
		}
		else if (Pattern1[i] == 'G')
		{
			Pattern2[Pattern1.length() - i - 1] = 'C';
		}
		else if (Pattern1[i] == 'T')
		{
			Pattern2[Pattern1.length() - i - 1] = 'A';
		}
	}
	cout << Pattern2;
	getchar();
	return 0;
}
