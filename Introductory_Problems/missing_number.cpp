#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i < n; i++)
    {
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        if (i != v[i - 1])
        {
            cout << i;
            break;
        }
    }
}
