#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

class Edge 
{
private:
    int v1, v2, weigh; 
public:
    Edge(int v1, int v2, int weight)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->weigh = weight;
    }
    int Ve1() const
    {
        return this->v1;
    }
    int Ve2() const
    {
        return this->v2;
    }
    int Weig() const
    {
        return this->weigh;
    }
};

vector<Edge> edge;
const int infinity = 1000000000;
vector<int> dist;
vector<int> parent;
vector<int> path;

int main()
{
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    int n, w;
    fin >> n;
    dist.resize(n, infinity);
    parent.resize(n, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> w;
            edge.push_back({ i, j, w });
        }
    int start;
    dist[0] = 0;
    for (int i = 0; i < n; i++) //Беллман форд, проверяем наличие цикла
    {
        start = -1;
        for (auto& j : edge)
        {
            if (dist[j.Ve2()] > dist[j.Ve1()] + j.Weig())
            {
                dist[j.Ve2()] = max(dist[j.Ve1()] + j.Weig(), -infinity);
                parent[j.Ve2()] = j.Ve1();
                start = j.Ve2();
            }
        }
    } 
    if (start == -1) 
        fout << "NO"; 
    else 
    {
        int end = start; // берём вершину, расстояние до которой изменилось
        for (int i = 0; i < n; i++) // заполнение массива предков
            end = parent[end];
        for (int cur = end; ; cur = parent[cur]) //проходимся по вершинам, чтобы войти в цикл
        {
            path.push_back(cur);
            if (cur == end && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end()); 
        fout << "YES" << endl;
        fout << path.size() << endl;
        for (auto& i : path)
            fout << i + 1 << " ";
    }
    return 0;
}