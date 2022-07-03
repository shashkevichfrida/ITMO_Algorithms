#include <iostream>
#include <fstream>

using namespace std;

int max(int number_one, int number_two)
    {
if (number_one > number_two)
return number_one;
else return number_two;
    }


int main()
{
int w, h;

ifstream fin("turtle.in");
ofstream fout;
fout.open("turtle.out");

fin >> w >> h;
int** arr = new int*[w];

for (int i = 0; i < w; i++)
    {
        arr[i] = new int[h];
    }



for (int i = w - 1; i >= 0; i--)
    {
        for (int j = 0; j < h; j++)
            {
                fin >> arr[i][j];
            }
    }

for (int i = 1; i < w; i++)
    {
        arr[i][0] += arr[i - 1][0];
    }


for (int j = 1; j < h; j++)
    {
        arr[0][j] += arr[0][j - 1];
    }


for (int i = 1; i < w; i++)
    {
        for (int j = 1; j < h; j++)
        {
        arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

fout << arr[w - 1][h - 1];


fin.close();
fout.close();


return 0;
}
