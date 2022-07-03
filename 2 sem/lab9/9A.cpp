#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<int> arr[100000];
vector<int> was;
vector<int> sort;
int fl = 0;

void dfs(int v)
{
    was[v] = 1;

    if (arr[v].size() != 0)
    {
        for (int i : arr[v])
        {
            if (was[i] == 1)
            {
                fl++;
            }
            else if (was[i] == 0)
            {
                dfs(i);
            }
        }
           
    }

    sort.push_back(v+1);
    was[v] = 2;
}

int main()
{
    int n, m;
    int a, b;
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");
    fin >> n >> m;

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
        if (fl == 0)
        {
            if (was[i] == 0)
            {
                dfs(i);
            }
        }
    }

    if (fl == 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            fout << sort[i] << " ";
        }
    }
    else
    {
        fout << -1;
    }

    fin.close();
    fout.close();
}