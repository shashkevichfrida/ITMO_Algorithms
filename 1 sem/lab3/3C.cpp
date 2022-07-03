#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");
    int n, m, k;
    fin >> n >> m >> k;
    string str, tmp;
    vector<string> arr, A;

    for (int i = 0; i < n; i++)
    {
        fin >> str;
        arr.push_back(str);
    }

    for (int i = 0; i < k; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
            for (int p = 0; p < n; p++)
            {
                tmp = arr[p];
                if (tmp[m - i - 1] == j)
                    A.push_back(tmp);
            }

        arr = A;
        A.clear();

    }

    for (int i = 0; i < n; i++)
        fout << arr[i] << endl;
    return 0;
}
