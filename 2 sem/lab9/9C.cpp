#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


vector<int> arr[100000];
vector<bool> was;
vector<int> col;
int fl = 0;


void dfs(int v, int now)
{
    was[v] = 1;
    col[v] = now;
    if (arr[v].size() != 0)
    {
        for (int i : arr[v])
        {
            if (was[i] == 0)
            {
                dfs(i, -now);
            }
            else if (col[i] != -now)
            {
                fl++;
                return;
            }
        }
    }
}

int main()
{
    int n, m, a, b;
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        {
            arr[a - 1].push_back(b - 1);
            arr[b - 1].push_back(a - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        was.push_back(0);
        col.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        if (was[i] == 0)
        {
            dfs(i,3);
        }
    }
    

    if (fl > 0)
    {
        fout << "NO";
    }
    else
    {
        fout << "YES";
    }

    fin.close();
    fout.close();
}