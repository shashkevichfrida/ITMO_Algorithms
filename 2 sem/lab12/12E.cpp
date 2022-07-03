#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<vector<int>> d;

void dfs(int v)
{
    d[v][0] = 0;
    d[v][1] = 1;

    for (int i : a[v])
        dfs(i);
    for (int i : a[v])
    {
        d[v][1] += d[i][0];
        d[v][0] += max(d[i][0], d[i][1]);
    }
}

int main()
{
    int n, v, root = 0;
    cin >> n;
    a.resize(n);
    d.resize(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (v == 0)
            root = i;
        else
            a[v - 1].push_back(i);
    }
    dfs(root);
    cout << max(d[root][0], d[root][1]);
}