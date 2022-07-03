#include <iostream>
#include <fstream>

using namespace std;

int binsearch1(int* arr, int key, int n)
{
	int left = -1;
	int right = n;
	
	while (left < right - 1)              
	{    
		int midle = (left + right) / 2;
		if (arr[midle] < key)
			left = midle;
		else
			right = midle;

	}
	return right;
}
int binsearch2(int* arr, int key, int n)
{
	int left = -1;
	int right = n;
	
	while (left < right - 1)
	{
		int midle = (left + right) / 2;
		if (arr[midle] <= key)
			left = midle;
		else
			right = midle;
	}
	return right - 1;
}



int main()
{
	ifstream fin("binsearch.in");
	ofstream fout("binsearch.out");
	int n, m;
	fin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		fin >> arr[i];

		fin >> m;
		for (int i = 0; i < m; i++)
		{
			int key;
			fin >> key;
			if (binsearch1(arr, key, n) > binsearch2(arr, key, n))
				fout << "-1 -1\n";
			else
				fout << binsearch1(arr, key, n) + 1 << " " << binsearch2(arr, key, n) + 1 << '\n';

		}
		return 0;
	

}