#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> arr2;
vector<int> was;
vector<char> win;

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
        if (arr[v].size() == 1)
        {
            if (win[arr[v][0]] == '*')
                win[v] = '$';
            else
            {
                win[v] = '*';
                for (int i : arr2[v])
                    win[i] = '$';
            }
        }
        else
        {
            int fl = 0;
            for (int i : arr[v])
            {
                if (win[i] == '*')
                {
                    fl++;
                    break;
                }
            }
            if (fl == 0)
            {
                win[v] = '*';
                for (int i : arr2[v])
                    win[i] = '$';
            }
        }
        
    }
    else
    {
        win[v] = '*';
        for (int i : arr2[v])
            win[i] = '$';
    }
}

int main()
{
    int n, m, a, b, s;
    ifstream fin("game.in");
    ofstream fout("game.out");
    fin >> n >> m >> s;
    arr.resize(n);
    arr2.resize(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
        arr2[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        was.push_back(0);
        win.push_back('.');
    }
    dfs(s - 1);
    if (win[s - 1] == '$') fout << "First player wins";
    else fout << "Second player wins";
    return 0;
}