#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const long long inf = 100000000000;

vector<long long> findLIS(vector<long long> a)   
{
	vector<long long> d;
	d.resize(a.size() + 1, inf);
	vector<long long> pos;
	pos.resize(a.size()+1);
	vector<long long> prev;
	prev.resize(a.size());
	long long lenght = 0;
	pos[0] = -1;
	prev[0] = -1;
	d[0] = -inf;
	for (int i = 0; i < a.size(); i++)
	{
		long long k = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[k - 1] < a[i] && a[i] < d[k])
		{
			d[k] = a[i];
			pos[k] = i;
			prev[i] = pos[k - 1];
			lenght = max(lenght, k);
		}
	}
	vector<long long> ans;
	long long p = pos[lenght];
	while (p != -1)
	{
		ans.emplace_back(a[p]);
		p = prev[p];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <long long> ans = findLIS(a);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}

}