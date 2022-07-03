#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<vector<int>, int>> a;
vector<vector<int>> d;

void dfs(int v)
{
    d[v][0] = 0;
    d[v][1] = a[v].second;

    for (int i : a[v].first)
        dfs(i);
    for (int i : a[v].first)
    {
        d[v][1] += d[i][0];
        d[v][0] += max(d[i][0], d[i][1]);
    }
}

int main()
{
    ifstream cin("selectw.in");
    ofstream cout("selectw.out");
    int n, v1, v2, root = 0;
    cin >> n;
    a.resize(n);
    d.resize(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v1 >> v2;
        if (v1 == 0)
        {
            root = i;
            a[i].second = v2;
        }
        else
        {
            a[v1 - 1].first.push_back(i);
            a[i].second = v2;
        }
    }
    dfs(root);
    cout << max(d[root][0], d[root][1]);
}