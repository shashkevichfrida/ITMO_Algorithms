#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;


vector<int> search(string str1, string str2)
{
	int n = str2.size();
	int m = str1.size();
	vector<int> ans;
	for (int i = 0; i < n-m+1; i++)
	{
		if (str2.substr(i, m) == str1)
			ans.push_back(i);
	}
	return ans;
}

int main()
{
	string str1, str2; 
	ifstream fin("search1.in");
	ofstream fout("search1.out");
	fin >> str1;
	fin >> str2;
	vector<int> ans;
	ans = search(str1, str2);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]+1 << ' ';
	}
	
}