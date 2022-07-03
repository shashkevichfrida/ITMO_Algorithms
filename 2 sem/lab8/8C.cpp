#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, m;
    int s, c;
    int count = 0;
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

    for (int i = 0; i < m; i++)
    {
        fin >> s >> c;
        s--;
        c--;
        if (arr[s][c] == 0)
            arr[s][c] = 1;
        else
            count = 1;
        if (arr[s][c] == 1 && arr[c][s] == 1)
            count = 1;
    }

    if (count == 1)
        fout << "YES";
    else
        fout << "NO";

    fin.close();
    fout.close();

}





