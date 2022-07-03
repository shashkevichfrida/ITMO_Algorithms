#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main()
{
    int n, m, a, b;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> m;
    vector <int> k(n);
    for (int i = 0; i < m; i++)
    {
        fin >> a >> b;
        k[a-1]++;
        k[b-1]++;
    }
    for (auto i: k)
    {
        fout << i << " ";
    }
    return 0;
}