#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> arr_t;
vector<int> was;
vector<int> comp;
vector<int> sort;
stack<int>st;
int k;

void dfs_g(int v)
{
    was[v] = 1;
    for (int i : arr[v])
    {
        if (was[i] == 0)
        {
            dfs_g(i);
        }
    }
    st.push(v);
}

void dfs_h(int u)
{
    was[u] = 1;
    comp.push_back(u);
    for (int i : arr_t[u])
    {
        if (was[i] == 0)
        {
            dfs_h(i);
        }
    }
}

int main()
{
    int n, m, a, b;
    ifstream fin("cond.in");
    ofstream fout("cond.out");
    fin >> n >> m;
    arr.resize(n);
    arr_t.resize(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
        arr_t[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        was.push_back(0);
        comp.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        if (was[i] == 0)
            dfs_g(i); 
    }
    was.clear();
    was.resize(n);
    sort.resize(n);
    k = 0;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (was[i] == 0)
        {
            comp.clear();
            dfs_h(i);
            k++;
            for (int j : comp)
                sort[j] = k;
        }
    }
    cout << k-- << endl;
    for (int i = 0; i < sort.size(); i++)
    {
        cout << sort[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}