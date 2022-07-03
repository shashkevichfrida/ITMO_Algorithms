#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<int> was;
vector<int> sort;
int gam = 1;

void dfs(int v)
{
    was[v] = 1;
    if (arr[v].size() != 0)
    {
        for (int i : arr[v])
        {
            if (was[i] == 0)
            {
                dfs(i);
            }
        }
    }
    sort.push_back(v);
}

int main()
{
    int n, m, a, b;
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");
    fin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; i++)
    {
        was.push_back(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (was[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        int fl = 0;
        for (int j : arr[sort[i]])
        {
            if (j == sort[i - 1])
                fl++;
        }
        if (fl == 0)
        {
            gam = 0;
            break;
        }
    }
    if (gam == 0) 
        fout << "NO";
    else
        fout << "YES";
    return 0;
}