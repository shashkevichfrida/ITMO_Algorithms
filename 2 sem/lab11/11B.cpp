#include <iostream>
#include <fstream>
#include <vector>
#define INF 0x3F3F3F3F

using namespace std;

vector<vector <int>> arr;

int main()
{
	int n, m, a, b, v;
	ifstream fin("pathsg.in");
	//ifstream fin("input.txt");
	ofstream fout("pathsg.out");
	fin >> n >> m;
	arr.resize(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++)
	{
			fin >> a >> b >> v;
			a--; 
			b--;
			arr[a][b] = v;
	}
	
	for (int k = 0; k < n; k++) //флойд
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((arr[i][k] < INF) && (arr[k][j] < INF))
				{
					if (arr[i][k] + arr[k][j] < arr[i][j])
						arr[i][j] = arr[i][k] + arr[k][j];
					
						
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}