#include <iostream>   
#include <fstream>  
#include <vector>  
#include <queue>  

using namespace std;

vector<bool> was;
queue <int> q;
vector<int> ras;
vector<int> arr[100000];

void bfs(int v, int n, int m)
{
    was[v] = 1;
    ras[v] = 0;
    q.push(v + 1);
    while (!q.empty())
    {
        int z = q.front();
        for (int i = 0; i < arr[z - 1].size(); i++)
        {
            int smez = arr[z - 1][i] + 1;
            if (was[smez - 1] == 0)
            {
                was[smez - 1] = 1;
                ras[smez - 1] = ras[z - 1] + 1;
                q.push(smez);
            }
        }
        q.pop();
    }
}

int main()
{

    int n, m, a, b;
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");
    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        was.push_back(0);
        ras.push_back(0);
    }


    for (int i = 0; i < m; i++) 
    {
        fin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (was[i] == 0)
            bfs(i, n, m);
    }
    for (int i = 0; i < n; i++)
    {
        fout << ras[i] << ' ';
    }

    fin.close();
    fout.close();
}