#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

struct graph
{
    int to;
    int capacity;
};

bool bfs(int s, vector<int>& dist, vector<vector<graph>>& g, int numV)
{

    queue<int> q;
    q.push(s);

    dist[s] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i].to;

            if (dist[to] == 0 && g[v][i].capacity != 0)
            {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    return dist[numV] != 0;
}

int dfs(int vertex, vector<vector<graph>>& g, int maxflow, int numV, vector<int>& dist)
{
    if (vertex == numV || maxflow == 0)
        return maxflow;

    for (int i = 0; i < g[vertex].size(); ++i)
    {
        if (dist[vertex] + 1 != dist[g[vertex][i].to])
            continue;

        int res = dfs(g[vertex][i].to, g, min(maxflow, g[vertex][i].capacity), numV, dist);

        if (res != 0)
        {
            g[vertex][i].capacity -= res;

            int v = g[vertex][i].to;

            for (int j = 0; j < g[v].size(); ++j)
            {
                if (g[v][j].to == vertex)
                {
                    g[v][j].capacity += res;
                    break;
                }
            }
            return res;
        }

    }
    return 0;
}

int main()
{
    ifstream fin("matching.in");
    ofstream fout("matching.out");

    int v1, v2, e, from, to;
    int maxflow = INF;
    int ansFlow = 0;
    fin >> v1 >> v2 >> e;

    vector<vector<graph>> g(v1 + v2 + 3, vector<graph>());
    vector<int> dist(v1 + v2 + 3, 0);

    for (int i = 0; i < e; ++i)
    {
        fin >> from >> to;

        g[from].push_back({ to + v1, 1 });
        g[to + v1].push_back({ from, 0 });
    }

    for (int j = 1; j <= v1; ++j)
    {
        g[v1 + v2 + 1].push_back({ j, 1 });
    }

    for (int j = 1; j <= v2; ++j)
    {
        g[j + v1].push_back({ v1 + v2 + 2, 1 });
    }

    while (bfs(v1 + v2 + 1, dist, g, v1 + v2 + 2))
    {
        ansFlow += dfs(v1 + v2 + 1, g, maxflow, v1 + v2 + 2, dist);
        dist.assign(dist.size(), 0);
    }

    fout << ansFlow;

    fin.close();
    fout.close();
    return 0;
}