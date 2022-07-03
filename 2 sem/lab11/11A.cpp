#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<long long>> arr;
vector<bool> was; 
vector<long long> dist;
const long long inf = 1000000000000000;

void dijkstra(long long s, int n)
{
    dist[s] = 0;    
    long long min;
    for (int i = 0; i < n; i++)
    {
        min = -1;
        for (int j = 0; j < n; j++)
        {
            if (was[j] == 0 && ((min == -1) || (dist[j] < dist[min])))
            {
                min = j;
            }
        }
            if (dist[min] == inf) break;
            was[min] = 1;
        
        for (int j = 0; j < n; j++)
        {
                if (dist[min] + arr[min][j] < dist[j])
                    dist[j] = dist[min] + arr[min][j];
        }
    }
}

int main()
{
    int n, s, f;
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
    fin >> n >> s >> f;
    s--;
    f--;
    int a;
    arr.resize(n, vector<long long>(n));
    was.resize(n, 0);
    dist.resize(n, inf);
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            fin >> a;
            if (a < 0)
                arr[i][j] = inf;
            else
            arr[i][j] = a;
        }
    }
    dijkstra(s, n);
        
    if (dist[f] != inf)
        cout << dist[f];
    else
        cout << -1;
}