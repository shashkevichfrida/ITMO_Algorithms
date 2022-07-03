#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

vector<int> a;
vector<int> p;
int full = 0;
int min_t = 0;

int parentIndex(int i)
{
    return (i - 1) / 2;
}

int parent(int* a, int i)
{
    return a[parentIndex(i)];
}

int left_child_index(int i)
{
    return 2 * i + 1;
}

int right_child_index(int i)
{
    return 2 * i + 2;
}

int find(int k)
{
    for (int i = 0; i < p.size(); ++i)
    {
        if (p[i] == k)
        {
            return i;
        }
    }
    return -1;
}

void sift_down(int i)
{
    int x = i;
    if ((left_child_index(i) < full) && (a[left_child_index(i)] < a[i]))
    {
        x = left_child_index(i);
    }
    if ((right_child_index(i) < full) && a[right_child_index(i)] < a[x])
    {
        x = right_child_index(i);
    }
    if (x != i)
    {
        swap(a[i], a[x]);
        swap(p[i], p[x]);
        sift_down(x);
    }
}

void sift_up(int i)
{
    while (a[i] < a[parentIndex(i)])
    {
        swap(a[i], a[parentIndex(i)]);
        swap(p[i], p[parentIndex(i)]);
        i = parentIndex(i);
    }
}

bool extract_min()
{
    if (a.empty())
    {
        return false;
    }
    min_t = a[0];

    swap(a[0], a[full - 1]);
    swap(p[0], p[full - 1]);


    a.pop_back();
    p.pop_back();
    full--;

    sift_down(0);

    return true;
}

void push(int v, int priority)
{
    a.push_back(v);
    p.push_back(priority);
    full++;
    sift_up(full - 1);
}

void decrease_key(int k, int m)
{
    int i = find(k);
    a[i] = m;
    sift_up(i);
}

int main()
{
    
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");


    string str;
    int priority = -1;

    while (fin >> str)
    {
        priority++;

        if (str == "push")
        {
            int k;
            fin >> k;

            push(k, priority);
        }

        if (str == "extract-min")
        {
            if (extract_min())
            {
                fout << min_t << "\n";
            }
            else
            {
                fout << "*" << "\n";
            }
        }

        if (str == "decrease-key")
        {
            int k, m;
            fin >> k >> m;
            decrease_key(k - 1, m);
        }
    }
    fin.close();
    fout.close();


    return 0;
}