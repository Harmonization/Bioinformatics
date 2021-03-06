#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> FrequentWords(string text, int k)
{
	vector<string> result;
	auto iter = result.cbegin();
	int *count = new int[text.length() - k + 1]();
	for (int i = 0; i < (text.length() - k + 1); i++)
	{
		for (int j = i; j < text.length() - k + 1; j++)
		{
			if (text.substr(i, k) == text.substr(j, k))
			{
				count[i]++;
			}
		}
	}
	int maxCount = 0;
	for (int i = 0; i < text.length() - k + 1; i++)
	{
		if (count[i] > maxCount) maxCount = count[i];
	}
	for (int i = 0; i < text.length() - k + 1; i++)
	{
		if (count[i] == maxCount) result.push_back(text.substr(i, k));
	}
	for (int i = 0; i < result.size() - 1; i++)
	{
		if (result[i] == result[i + 1]) result.erase(iter + i - 1);
	}
	delete[]count;
	return result;
}
int main()
{
	string text;
	int k;
	cin >> text;
	cin >> k;
	vector<string> VecVec = FrequentWords(text, k);
	for (int i = VecVec.size() - 1; i >= 0; i--)
	{
		cout << VecVec[i] << " ";
	}
	getchar();
	getchar();
	return 0;
}
