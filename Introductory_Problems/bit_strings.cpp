#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    ll i = 1;
    ll mod = 1e9 + 7;

    for (int j = 0; j < n; j++)
    {
        i = (i * 2) % mod;
    }
    cout << i;
}