#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int k = 0;

void board(int a, int b)
{
    int n = arr.size();
    int m = arr[0].size();
    if (a == m - 3 && b == n - 3) 
    {
        k++;
        return;
    }
    else
    {
        if (arr[b + 2][a - 1] == 0) board(a - 1, b + 2);
        if (arr[b + 2][a + 1] == 0) board(a + 1, b + 2);
        if (arr[b + 1][a + 2] == 0) board(a + 2, b + 1);
        if (arr[b - 1][a + 2] == 0) board(a + 2, b - 1);
    }
}

int main()
{
    int n, m;
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");
    fin >> n >> m;
    n += 4;
    m += 4;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1 || i - 1 == 0 || i + 1 == n - 1 || j - 1 == 0 || j + 1 == m - 1)
            {
                arr[i][j] = 1;
            }
            else
                arr[i][j] = 0;
            //cout << arr[i][j];
        }
        //cout << '\n';
    }
    board(2, 2);
    fout << k;
}