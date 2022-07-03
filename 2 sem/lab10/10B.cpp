#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> f;
vector<int> was;
vector<vector<int>> arr;
vector<double> dist;

void MST(int v)
{
    dist[v] = 0;
    for (int i = 0; i < arr.size(); i++)
    {
       int min_e = -1;
       for (int j = 0; j < arr[i].size(); j++)
       {
           if (was[j] == 0 && (min_e == -1 || dist[j] < dist[min_e]))
               min_e = j;
       }
       was[min_e] = 1;
       for (int j = 0; j < arr[i].size(); j++)
       {
           if (was[j] == 0 && arr[min_e][j] < dist[j] && min_e != j) 
               dist[j] = arr[min_e][j];  
       }
    }
}

int main()
{
    int n;
    int a, b;
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
    fin >> n;
    f.resize(n);
    was.resize(n);
    dist.resize(n);
    const double inf = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        fin >> a >> b;
        f[i].first = a;
        f[i].second = b;     
        was[i] = 0;
        dist[i] = inf;
    }
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            int ves = pow(f[i].first - f[j].first, 2) + pow(f[i].second - f[j].second, 2);
            arr[i][j] = ves;
        }
    }
    MST(0);
    double min_ost = 0;
    for (int i : dist)
    {
        min_ost += sqrt(i);
    }
    fout.precision(10);
    fout << min_ost;
    return 0;
}

