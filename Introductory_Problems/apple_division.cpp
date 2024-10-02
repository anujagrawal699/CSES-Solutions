#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define ll long long
using namespace std;
ll maxi = 0;

void solve(ll i, ll n, vector<ll> &apple, ll tar, ll half)
{
    if (tar == 0)
    {
        maxi = half;
        return;
    }
    if (i == n)
    {
        maxi = max(maxi, half - tar);
        return;
    }
    if (apple[i] <= tar)
    {
        solve(i + 1, n, apple, tar - apple[i], half);
    }
    solve(i + 1, n, apple, tar, half);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> apple(n);
    for (auto &it : apple)
        cin >> it;
    ll sum = accumulate(apple.begin(), apple.end(), 0LL);
    ll half = sum / 2;
    solve(0, n, apple, half, half);
    ll second_half = sum - maxi;
    cout << abs(maxi - second_half) << endl;
}