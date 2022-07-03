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

vector<int> kmp(string str1, string str2)
{
	int n = str1.size();
	int m = str2.size();
	vector<int> ans;
	vector<int> p = prefix(str1 + "#" + str2);
	for (int i = 0; i < m ; i++)
	{
		if (p[n + i + 1] == n) //поиск совпадающих подстрок из str2 со строкой str1
			ans.push_back(i - n+1);
	}
	return ans;
}
int main()
{
	vector<int> ans;
	string str1, str2;
	ifstream fin("search2.in");
	ofstream fout("search2.out");
	fin >> str1;
	fin >> str2;
	ans = kmp(str1, str2);
	cout << ans.size()<<endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1 << ' ';
	}
}

