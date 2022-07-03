#include <iostream>  
#include <fstream> 
#include <vector>
#include <queue>

using namespace std;

vector<char> arr[100000];
vector<bool> was[100000];
vector<string>pat[100000];
queue<int> q;

void bfs(int vi, int vj, int n, int m)
{
    was[vi][vj] = 1;
    q.push(vi);
    q.push(vj);
    int z, h;
    while (!q.empty())
    {
        z = q.front();
        q.pop();
        h = q.front();
        q.pop();
        if (was[z][h + 1] == 0)
        {
            was[z][h + 1] = 1;
            q.push(z);
            q.push(h+1);
            pat[z][h + 1] = pat[z][h] + "R";
            if (arr[z][h + 1] == 'T')
                return;
        }
        if (was[z][h - 1] == 0)
        {
            was[z][h - 1] = 1;
            q.push(z);
            q.push(h - 1);
            pat[z][h - 1] = pat[z][h] + "L";
            if (arr[z][h - 1] == 'T')
                return;
        }
        if (was[z-1][h] == 0)
        {
            was[z-1][h] = 1;
            q.push(z-1);
            q.push(h);
            pat[z - 1][h] = pat[z][h] + "U";
            if (arr[z-1][h] == 'T')
                return;
        }
        if (was[z+1][h] == 0)
        {
            was[z+1][h] = 1;
            q.push(z+1);
            q.push(h);
            pat[z + 1][h] = pat[z][h] + "D";
            if (arr[z+1][h] == 'T')
                return;
        }
    }
}

int main()
{
    int n, m;
    int s_x = 0, s_y = 0, f_x = 0, f_y = 0;
    char a;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> m;
    n += 2;
    m += 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i].push_back('0');
            was[i].push_back(0);
            pat[i].push_back("");
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            fin >> a;
            arr[i][j] = a;            
        }
    }
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1 || arr[i][j] == '#')
                was[i][j] = 1;
            if (arr[i][j] == 'S')
            {
                s_x = i;
                s_y = j;
            }    
            if (arr[i][j] == 'T')
            {
                f_x = i;
                f_y = j;
            }
        }
    }
    bfs(s_x, s_y, n, m);
    if (pat[f_x][f_y].length() == 0)
        fout << -1;
    else
        fout << pat[f_x][f_y].length() << '\n' << pat[f_x][f_y];
}