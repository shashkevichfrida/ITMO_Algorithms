#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;

int n;
vector<double> h;

double B()
{
	double left = 0, right = h[0];
	while (right - left > 0.000001)
	{
		h[1] = (left + right) / 2;
		bool k = true;
		for (int i = 2; i < n; i++)
		{
			h[i] = 2 * h[i - 1] - h[i - 2] + 2;
			if (h[i] < 0)
			{
				k = false;
				break;
			}
		}
		if (k) {
			right = h[1];
		}
		else
		{
			left = h[1];
		}

	
	}
	return h[n - 1];

}
int main()
{
	ifstream fin("garland.in");
	ofstream fout("garland.out");
	fin >> n;
	h.resize(n);
	fin >> h[0];
	double a = B();
	fout.precision(2);			
	fout << fixed << a;
	fin.close();
	fout.close();
	return 0;
}