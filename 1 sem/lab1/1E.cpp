#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    int n;
    ifstream fin;
    fin.open("sortland.in");
    ofstream fout;
    fout.open ("sortland.out");
    fin >> n;
    float* arr= new float[n];

    for (int i = 0; i < n; i++)
    fin >> arr[i];

    int* index= new int[n];
    for (int i = 0; i < n; i++)
    index[i] = i + 1;

    int h;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                h = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = h;
                h = index[j];
                index[j] = index[j + 1];
                index[j + 1] = h;
            }
        }
    }

    fout << index[0] << " " << index[(n-1)/2]<< " "<< index[n-1];

    return 0;
}

