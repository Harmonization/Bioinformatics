#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
vector <string> res;
int F(string str1, string str2)
{
	int n = 0;
	if (str1.length() == str2.length())
	{
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] != str2[i]) n++;
		}
	}
	return n;
}
void print(vector <string> result)
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] + " ";
	}
}
class product
{
	typedef product *product_ptr;
	typedef std::vector<std::string> vstring;
	typedef std::vector<std::string::const_iterator> vstring_iter;

	const vstring data;
	const size_t repeat;

public:
	class iterator : public std::iterator<
		std::input_iterator_tag,
		std::string,
		long,
		std::string *,
		std::string &>
	{
		const product_ptr prod;
		vstring_iter iters;

	public:
		iterator(const vstring_iter &iters, const product_ptr &prod) : iters(iters), prod(prod) { }
		iterator &operator++() {
			const size_t data_size = prod->data.size();
			for (int i = iters.size() - 1; i >= 0; --i)
			{
				++iters[i];
				if (i && iters[i] == prod->data[i % data_size].end())
					iters[i] = prod->data[i % data_size].begin();
				else
					break;
			}
			return *this;
		}
		bool operator==(const iterator &other) const {
			if (prod != other.prod || iters.size() != other.iters.size())
				return false;
			return iters == other.iters;
		}
		bool operator!=(const iterator &other) const
		{
			return !(*this == other);
		}
		std::string operator*() const {
			const size_t len = prod->repeat * prod->data.size();
			char *buffer = new char[len + 1]{ 0 };
			for (int i = len - 1; i >= 0; --i)
				buffer[i] = *iters[i];
			return std::string(buffer);
		}
	};

	product(const vstring &value, const int repeat = 1) : data(value), repeat(repeat) {}
	iterator begin() const {
		vstring_iter iters(data.size() * repeat);
		for (size_t i = 0; i < iters.size(); ++i)
			iters[i] = data[i % data.size()].begin();
		return iterator(iters, product_ptr(this));
	}
	iterator end() const {
		vstring_iter iters(data.size() * repeat);
		iters[0] = data[0].end();
		for (size_t i = 1; i < iters.size(); ++i)
			iters[i] = data[i % data.size()].begin();
		return iterator(iters, product_ptr(this));
	}
};
vector <string> Combo(int k)
{
	vector <string> result;
	for (const std::string data : product({ "ACGT" }, k))
		result.push_back(data);
	return result;
}
int dist(string Pattern, string DNA)
{
	int k = Pattern.length();
	int n = k;
		for (int i = 0; i < DNA.length() - k + 1; i++)
		{
			for (int j = 0; j < Pattern.length(); j++)
			{
				if (F(Pattern, DNA.substr(i, Pattern.length())) < n) n = F(Pattern, DNA.substr(i, Pattern.length()));
			}
		}
	return n;
}
string Median(vector<string> DNA, int k)
{
	string result;
	int d = 100;
	vector <string> combo = Combo(k);
	for (int l = 0; l < combo.size(); l++)
	{
		int count = 0;
		for (int i = 0; i < DNA.size(); i++)
		{
			count += dist(combo[l], DNA[i]);
		}
		if (count < d)
		{
			d = count;
			result = combo[l];
		}
	}
	return result;
}

vector <string> Repeat(vector <string> result)
{
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = i + 1; j < result.size(); j++)
		{
			if (result[i] == result[j]) result.erase(result.begin() + j);
		}
	}
	return result;
}
int main()
{
	vector <string> DNA;
    int k;
    cin >> k;
    for(int i = 0; i < 50; i++)
    {
        string str;
        cin >> str;
        if(str != "")
        DNA.push_back(str);
    }
	cout << Median(DNA, k);
	getchar();
	return 0;
}