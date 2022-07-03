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

        int result = dfs(g[vertex][i].to, g, min(maxflow, g[vertex][i].capacity), numV, dist);

        if (result != 0)
        {
            g[vertex][i].capacity -= result;

            int v = g[vertex][i].to;

            for (int j = 0; j < g[v].size(); ++j)
            {
                if (g[v][j].to == vertex)
                {
                    g[v][j].capacity += result;
                    break;
                }
            }
            return result;
        }

    }
    return 0;
}

int main()
{
    ifstream fin("maxflow.in");
    ofstream fout("maxflow.out");

    int v, e, from, to, c;
    int maxflow = INF;
    int ansFlow = 0;
    fin >> v >> e;

    vector<vector<graph>> g(v + 1, vector<graph>());
    vector<int> dist(v + 1, 0);

    for (int i = 0; i < e; ++i)
    {
        fin >> from >> to >> c;

        g[from].push_back({ to, c });
        g[to].push_back({ from, 0 });
    }

    while (bfs(1, dist, g, v))
    {
        ansFlow += dfs(1, g, maxflow, v, dist);
        dist.assign(dist.size(), 0);
    }

    fout << ansFlow;
}