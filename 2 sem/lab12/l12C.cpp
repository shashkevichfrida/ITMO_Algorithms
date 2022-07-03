#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF INT_MAX

using namespace std;

struct graph
{
    int to;
    int capacity;
    int numberE;
    int currentEdgeFlow;
};

bool bfs(int s, vector<int>& dist, vector<vector<int>>& EdgeIndex, vector<graph>& edges, int numV)
{
    queue<int> q;
    q.push(s);

    dist[s] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < EdgeIndex[v].size(); ++i)
        {
            int to = edges[EdgeIndex[v][i]].to;

            if (dist[to] == 0 && edges[EdgeIndex[v][i]].capacity - edges[EdgeIndex[v][i]].currentEdgeFlow > 0)
            {
                q.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    return dist[numV] != 0;
}

int dfs(int vertex, vector<vector<int>>& EdgeIndex, vector<graph>& edges, int maxflow, int numV, vector<int>& dist, vector<int>& current)
{
    if (vertex == numV || maxflow == 0)
        return maxflow;

    for (; current[vertex] < EdgeIndex[vertex].size(); ++current[vertex]) 
    {
        if (dist[vertex] + 1 != dist[edges[EdgeIndex[vertex][current[vertex]]].to])
            continue;

        int result = dfs(edges[EdgeIndex[vertex][current[vertex]]].to, EdgeIndex, edges, min(maxflow, edges[EdgeIndex[vertex][current[vertex]]].capacity - edges[EdgeIndex[vertex][current[vertex]]].currentEdgeFlow), numV, dist, current);

        if (result != 0)
        {
            edges[EdgeIndex[vertex][current[vertex]]].currentEdgeFlow += result;

            edges[EdgeIndex[vertex][current[vertex]] ^ 1].currentEdgeFlow -= result;

            return result;
        }
    }
    return 0;
}

int dfs2(int vertex, vector<vector<int>>& EdgeIndex, vector<graph>& edges, int flow, int numV, vector<int>& dist, vector<vector<int>>& decompFlow)
{
    if (vertex == numV)
    {
        decompFlow.push_back(vector<int>());
        return flow;
    }
    for (int i = 0; i < EdgeIndex[vertex].size(); ++i)
    {
        if (edges[EdgeIndex[vertex][i]].currentEdgeFlow > 0)
        {
            int res = dfs2(edges[EdgeIndex[vertex][i]].to, EdgeIndex, edges, min(flow, edges[EdgeIndex[vertex][i]].currentEdgeFlow), numV, dist, decompFlow);

            if (res > 0)
            {
                edges[EdgeIndex[vertex][i]].currentEdgeFlow -= res; 

                decompFlow.back().push_back(edges[EdgeIndex[vertex][i]].numberE);

                if (vertex == 1)
                {
                    decompFlow.back().push_back(decompFlow.back().size());
                    decompFlow.back().push_back(res); 

                    reverse(decompFlow.back().begin(), decompFlow.back().end());
                }
                return res;
            }
        }
    }
    return 0;
}

int main()
{
    ifstream fin("decomposition.in");
    ofstream fout("decomposition.out");

    int v, e, from, to, c;
    int maxflow = INF;
    int ansFlow = 0;
    fin >> v >> e;

    vector<vector<int>> EdgeIndex(v + 1);
    vector<vector<graph>> g(v + 1);
    vector<graph> edges;
    vector<int> dist(v + 1, 0);
    vector<vector<int>> decompFlow;

    for (int i = 0; i < e; ++i)
    {
        fin >> from >> to >> c;

        EdgeIndex[from].push_back(edges.size());
        edges.push_back({ to, c, i + 1, 0 });
        EdgeIndex[to].push_back(edges.size());
        edges.push_back({ from, 0, i + 1, 0 });
    }

    vector<int> current(v + 1, 0);

    while (bfs(1, dist, EdgeIndex, edges, v))
    {
        while (dfs(1, EdgeIndex, edges, maxflow, v, dist, current))
        {
        }
        dist.assign(dist.size(), 0);
        current.assign(current.size(), 0);
    }

    while (dfs2(1, EdgeIndex, edges, INT_MAX, v, dist, decompFlow))
    {
    }

    fout << decompFlow.size() << '\n';

    for (int i = 0; i < decompFlow.size(); ++i)
    {
        for (int j = 0; j < decompFlow[i].size(); ++j)
        {
            fout << decompFlow[i][j] << ' ';
        }

        fout << '\n';
    }
}