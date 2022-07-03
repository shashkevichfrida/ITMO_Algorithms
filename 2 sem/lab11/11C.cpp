#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair <long long, long long>>> arr;
vector<int> p;
vector<long long> metka;
const long long inf = 1000000000000000;

void deikstra(long long s) //алгоритм дейкстры
{
    int n = metka.size();
    metka[s] = 0; //выставляем первой вершине метку 0
    priority_queue < pair<int, int> > q; //создаем приоритетную очередь чтобы избавиться от проверки на минимульную вершину
    q.push(make_pair(0, s));
    while (!q.empty()) 
    {
        int v = q.top().second;
        int cur_d = -q.top().first;//priority_queue упорядочивает элементы по убыванию, поэтому помещаем в качестве элементов first расстояния со знаком минус
        q.pop();                                       
        if (cur_d > metka[v])  continue;
        for (size_t j = 0; j < arr[v].size(); ++j) 
        {
            int to = arr[v][j].first, len = arr[v][j].second;
            if (metka[v] + len < metka[to]) 
            {
                metka[to] = metka[v] + len;
                p[to] = v;
                q.push(make_pair(-metka[to], to));
            }
        }
    }
}

int main()
{
    int n, m, a, b, v;
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
    fin >> n >> m;
    arr.resize(n);//список смежности
    p.resize(n);
    metka.resize(n, inf);//создаем вектор меток для дейкстры, которые изначально бесконечность
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> v;
        pair <long long, long long> versh; //вектор пара смежная верш и вес
        versh.first = b - 1;
        versh.second = v;
        arr[a - 1].push_back(versh);
        versh.first = a - 1;
        versh.second = v;
        arr[b - 1].push_back(versh);
    }
    
    deikstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << metka[i] << ' ';
    }
}