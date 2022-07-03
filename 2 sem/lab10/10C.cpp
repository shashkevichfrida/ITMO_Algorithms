#include <iostream>  
#include <fstream>  
#include <vector> 
#include <algorithm> 

using namespace std;

struct Edge
{
    long long a, b, c;
};

vector<Edge> f;
vector<int> was;
long long dist = 0, versh = 0;
int zvet = 0;

bool compare( Edge& first, Edge& second)
{
    return first.c < second.c;
}

void Kraskal(long long v1, long long v2, long long w)
{
    if (was[v1] == 0 && was[v2] == 0)
    {
        zvet++;
        was[v1] = zvet;
        was[v2] = zvet;
        versh += 2;
        dist += w;
    }
    else if ((was[v1] == 0 && was[v2] != 0) || (was[v2] == 0 && was[v1] != 0))
    {
        if (was[v1] != 0) was[v2] = was[v1];
        else was[v1] = was[v2];
        versh += 1;
        dist += w;
    }
    else
    {
        if (was[v1] != was[v2])
        {
            zvet++;
            int cv1 = was[v1];
            int cv2 = was[v2];
            for (int i = 0; i < was.size(); i++)
            {
                if (was[i] == cv1 || was[i] == cv2)
                {
                    was[i] = zvet;
                }
            }
            dist += w;
        }
    }
}

int main()
{
    int n, m;
    long long a, b, c;
    //ifstream fin("input2.txt");
    //ofstream fout("output.txt");
    ifstream fin("spantree3.in");  
    ofstream fout("spantree3.out");  
    fin >> n >> m;
    int petly = 0;
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b >> c;
        if (a != b) f.push_back(Edge{ a - 1, b - 1, c });
        else petly++;
    }
    sort(f.begin(), f.end(), compare);
    was.resize(n, 0);
    for (int i = 0; i < m - petly; i++)
    {
        if (versh <= n)
            Kraskal(f[i].a, f[i].b, f[i].c);
    }
    cout << dist;
    return 0;
}