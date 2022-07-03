#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("check.in");
    ofstream fout("check.out");

    int n;
    fin >> n;


    int* tree = new int[n * 3];
    for (int i = 0; i < n * 3; i++)
    {
        fin >> tree[i];
    }
    vector<vector<int>> checks;
    checks.emplace_back(vector<int>{1, INT_MIN, INT_MAX});

    int fl = 0;

    if (n != 0)
    {
        while (!checks.empty())
        {
            int index = (checks.back()[0]) * 3 - 3;
            int minimum = checks.back()[1];
            int maximum = checks.back()[2];
            checks.pop_back();


            if (tree[index] <= minimum || tree[index] >= maximum)
            {
                fout << "NO";
                fl++;
                break;
            }
            if (tree[index + 1] != 0)
            {
                checks.emplace_back(vector<int>{tree[index+1], minimum, tree[index]});
            }
            if (tree[index + 2] != 0)
            {
                checks.emplace_back(vector<int>{tree[index+2], tree[index], maximum});
            }
        }
    }

    if (fl == 0) fout << "YES";
    fin.close();
    fout.close();
    return 0;
}