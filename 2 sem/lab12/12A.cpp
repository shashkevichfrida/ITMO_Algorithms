﻿#include <iostream>
#include <vector>

using namespace std;

vector<int> FindLIS(vector<int> a)
{
    int n = a.size();
    int d[n - 1];
    int prev[n - 1];

    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && d[j] + 1 > d[i])
            {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
    }
    int pos = 0;
    int l = d[0];
    for (int i = 0; i < n; i++)
        if (d[i] > l)
        {
            pos = i;
            l = d[i];
        }

    vector<int> ans;
    while (pos != -1)
    {
        ans.push_back(a[pos]);
        pos = prev[pos];
    }
    return ans;
}

int main()
{
    int n, a;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    vector<int> ans = FindLIS(arr);
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}