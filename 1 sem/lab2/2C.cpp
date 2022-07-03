#include <iostream>
#include <fstream>

using namespace std;

long long inverse = 0;
void merge(long long* Arr, long left, long mid, long right);
void mergeSortRecursive(long long* Arr, long left, long right);

void merge(long long* Arr, long left, long mid, long right)
{
	long i = 0, j = 0;
	long len_of_left_side = mid - left;
	long long* result = new long long[right - left];
	while (left + i < mid && mid + j < right)
	{
		if (Arr[left + i] <= Arr[mid + j])
		{
			result[i + j] = Arr[left + i];
			i++;
		}
		else
		{
			result[i + j] = Arr[mid + j];
			j++;
			inverse += len_of_left_side - i;
		}
	}
	while (left + i < mid)
	{
		result[i + j] = Arr[left + i];
		i++;
	}
	while (mid + j < right)
	{
		result[i + j] = Arr[mid + j];
		j++;
		inverse += len_of_left_side - i;
	}
	for (i = 0; left + i < right; i++)
	{
		Arr[left + i] = result[i];
	}
}
void mergeSortRecursive(long long* Arr, long left, long right)
{
	if (left + 1 >= right) return;
	int mid = (left + right) / 2;
	mergeSortRecursive(Arr, left, mid);
	mergeSortRecursive(Arr, mid, right);
	merge(Arr, left, mid, right);
}



int main()
{
	long long n;
	ifstream fin;
	ofstream fout;
	fin.open("inversions.in");
	fout.open("inversions.out");

	fin >> n;
	long long* Arr = new long long[n];
	for (int i = 0; i < n; i++)
		fin >> Arr[i];

	mergeSortRecursive(Arr, 0, n);
	fout << inverse;

	fin.close();
	fout.close();
	return 0;
}