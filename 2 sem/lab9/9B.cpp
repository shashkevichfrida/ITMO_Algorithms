#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


vector<vector<int>> arr;
vector<int> was;
vector<int> put;
int fl = 0;
int start;

void dfs(int v)
{
    if (fl == 0)
    {
        was[v] = 1;
        put.push_back(v);
        if (arr[v].size() != 0)
        {
            for (int i : arr[v])
            {
                if (was[i] == 1)
                {
                    put.push_back(i);
                    fl++;
                    start = i;
                    return;
                }
                else if (was[i] == 0)
                {
                    dfs(i);
                }
                if (fl > 0) return;
            }
        }
        was[v] = 2;
        put.pop_back();
    }
    else return;
}

int main()
{
    int n, m;
    int a, b;
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
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
            {
                dfs(i);
                if (fl > 0) break;
            }
        }
    }



    if (fl == 0)
    {
        fout << "NO";
    }
    else
    {
        fout << "YES" << endl;
        int p = 0;
        int i = 0;
        while (put[i++] != start)
            p++;
        for (int j = p + 1; j < put.size(); j++)
        {
            fout << put[j] + 1 << ' ';
        }
    }
    fin.close();
    fout.close();
    return 0;
}