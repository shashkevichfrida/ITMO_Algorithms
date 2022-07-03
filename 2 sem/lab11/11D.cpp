#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<pair <long long, long long>>> g;
const long long inf = 9223372036854775807;
vector<long long> metka;

void dfs(int v,vector<int>& was)
{
    was[v] = 1;
    for (long long i = 0; i < g[v].size(); i++)
    {
        if (was[g[v][i].first] == 0)
        {
            dfs(g[v][i].first, was);
        }
    }
}

void bellman(long long s)
{
    int n = metka.size();
    metka[s] = 0;
    for (long long k = 0; k < n; k++)
    {
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < g[i].size(); j++)
            {
                long long u = i;
                long long v = g[i][j].first;
                long long w = g[i][j].second;
                if ((metka[u] < inf) && (metka[u] + w < metka[v]))
                    metka[v] = metka[u] + w;
            }
        }
    }
}

int main()
{
    long long n, m;
    long long a, b, w, start;
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    ifstream fin("path.in");
    ofstream fout("path.out");
    fin >> n >> m >> start;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> w;
        g[a - 1].push_back({ b - 1,w });
    }
    metka.resize(n, inf);
    bellman(start - 1);
    vector<int> was(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (metka[i] < inf && metka[g[i][j].first] > metka[i] + g[i][j].second && was[g[i][j].first] == 0)
            {
                dfs(g[i][j].first, was);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (metka[i] == inf)
            cout << '*' << endl;
        else if (was[i] > 0 || metka[i] < -5e18)
            cout << '-' << endl;
        else
            cout << metka[i] << endl;
    }
}