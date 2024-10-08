#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    sort(v.begin(), v.end());

    ll prev = 0;
    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > ans)
        {
            break;
        }
        ans += v[i];
    }

    cout << ans << endl;
}
