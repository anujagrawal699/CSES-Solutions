#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    sort(v.begin(), v.end());
    int mid = v[n / 2];
    ll ans = 0;
    for (auto it : v)
    {
        ans += abs(mid - it);
    }
    cout << ans << endl;
}