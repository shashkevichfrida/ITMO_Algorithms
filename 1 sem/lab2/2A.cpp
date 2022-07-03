#include <iostream>
#include <fstream>

using namespace std;

void merge(int* Arr, int left, int mid, int right);
void mergeSortRecursive(int* Arr, int left, int right);

void merge(int* Arr, int left, int mid, int right)
{
	int i = 0, j = 0;
	int* result = new int[right - left];
	while (left + i < mid && mid + j < right)
	{
		if (Arr[left + i] < Arr[mid + j])
		{
			result[i + j] = Arr[left + i];
			i++;
		}
		else
		{
			result[i + j] = Arr[mid + j];
			j++;
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
	}
	for (i = 0; left + i < right; i++)
	{
		Arr[left + i] = result[i];
	}
}
void mergeSortRecursive(int* Arr, int left, int right)
{
	if (left + 1 >= right) return;
	int mid = (left + right) / 2;
	mergeSortRecursive(Arr, left, mid);
	mergeSortRecursive(Arr, mid, right);
	merge(Arr, left, mid, right);
}



int main()
{
	int n;
	ifstream fin;
	ofstream fout;
	fin.open("sort.in");
	fout.open("sort.out");

	fin >> n;
	int* Arr = new int[n];
	for (int i = 0; i < n; i++)
		fin >> Arr[i];

	mergeSortRecursive(Arr, 0, n);
	
	for (int i = 0; i < n; i++)
		fout << Arr[i] << " ";

	fin.close();
	fout.close();
	return 0;
}