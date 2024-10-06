#include <iostream>
#include <set>
#include <vector>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;

    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;
}