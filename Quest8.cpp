#include <iostream>
#include <vector>
using namespace std;

long long Power(int n)
{
	vector <long long> count(n + 1);
	count[0] = 1;
	vector <long long> mass = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };

	for (int i = 57; i <= n; i++)
	{
		for (int j = 0; j < mass.size(); j++)
		{
			if (i - mass[j] >= 0)
			{
				count[i] += count[i - mass[j]];
			}
		}
	}
	return count[n];
}

int main()
{
	int m;
	cin >> m;
	long long a = Power(m);
	cout << a << endl;
	getchar();
	return 0;
}