#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int n;
    ifstream fin("height.in");
    ofstream fout("height.out");
    fin >> n;
    int* arr = new int[n * 3];
    for (int i = 0; i < n * 3; i++)
    {
        fin >> arr[i];
    }
    for (int i = 0; i < n * 3; i+=3)
    {
        if (arr[i + 1] != 0)
        {
            arr[arr[i + 1]*3-3] = arr[i] + 1;
        }
        if (arr[i + 2] !=  0)
        {
            arr[arr[i + 2] * 3-3] = arr[i] + 1;
        }
    }
    int h = 0;
    for (int i = 0; i < n * 3; i+=3)
    {
        h = max(arr[i]-arr[0]+1, h);
    }
    fout << h;

    fin.close();
    fout.close();
    return 0;
}