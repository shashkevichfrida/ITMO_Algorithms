#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int n;
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    fin >> n;
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fin >> arr[i];
    }

    int fl = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (2 * i <= n)
        {
            if (arr[i] > arr[i * 2])
                fl += 1;
            else fl = fl;
        }
        if (2 * i + 1 <= n)
        {
            if (arr[i] > arr[2 * i + 1])
                fl += 1;
            else fl == fl;
        }
    }
    if (fl == 0)  
        fout << "YES\n";
    else 
        fout << "NO\n";
    fin.close();
    fout.close();

}