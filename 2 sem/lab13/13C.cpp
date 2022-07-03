#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> prefix(string str)
{
	vector<int> p;
	p.resize(str.size());
	p[0] = 0;
	for (int i = 1; i < str.size(); i++)
	{
		int k = p[i - 1];
		while (k > 0 && str[i] != str[k])
			k = p[k - 1];
		if (str[i] == str[k])
			k++;
		p[i] = k;
	}
	return p;
}


int main()
{
	vector<int> ans;
	string str1;
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	fin >> str1;
	vector<int> p = prefix(str1);
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << ' ';
	}
}

