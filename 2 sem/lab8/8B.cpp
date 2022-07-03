#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, v;
    int count = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> v;
            arr[i][j] = v;
        }
       
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && arr[i][j] == 1)
                count++;
            if (arr[i][j] != arr[j][i])
                count++;
        }

    }


    if (count > 0)
        fout << "NO";
    else
        fout << "YES";
    fin.close();
    fout.close();
}