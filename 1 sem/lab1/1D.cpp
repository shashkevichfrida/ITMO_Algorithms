#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    ifstream fin;
    fin.open("smallsort.in");
    ofstream fout;
    fout.open("smallsort.out");
    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << endl;
    }
    fin.close();
    fout.close();
    delete[] arr;
    return 0;
}
