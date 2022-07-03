#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, m, t;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}

	}
	int s, c;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			fin >> c >> s;
			arr[c - 1][s - 1] = 1;

		}

	}

	for (int c = 0; c < n; c++)
	{

		for (int s = 0; s < n; s++)
		{

			fout << arr[c][s] << ' ';
		}
		if (c != (n - 1))
			fout << '\n';
		
	}

	fin.close();
	fout.close();

}


