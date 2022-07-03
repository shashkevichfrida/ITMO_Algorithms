#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


vector<int> arr[100000];
vector<bool> was;
vector<int> comp;


void dfs(int v, int num)
{
    was[v] = 1;
    comp[v] = num;
    if (arr[v].size() != 0) 
    {
        for (int i : arr[v])
            if (was[i] == 0) 
                dfs(i, num); 
    }
}

int main()
{
    int n, m;
    int a, b;
    int num = 0;
    ifstream fin("components.in");
    ofstream fout("components.out");
    fin >> n >> m;

    for (int i = 0; i < m; i++) 
    {
        fin >> a >> b; 
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++)
    {
        was.push_back(0); 
        comp.push_back(0); 
    }

    for (int i = 0; i < n; i++)
    {
        if (was[i] == 0)
        {
            num++;
            dfs(i, num); 
        }
    }

    fout << num << '\n';

    for (int i = 0; i < n; i++)
    {
        fout << comp[i] << " ";
    }

    fin.close();
    fout.close();
}