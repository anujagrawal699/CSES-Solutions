#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            moves += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << moves;
}