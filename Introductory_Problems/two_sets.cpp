#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll totalSum = n * (n + 1) / 2;
    if (totalSum % 2 == 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        vector<ll> vis(n + 1, 0);
        ll i = n;
        vector<ll> set1;
        vector<ll> set2;
        ll s1Sum = 0;
        while (s1Sum + i <= totalSum / 2)
        {
            vis[i] = 1;
            set1.push_back(i);
            s1Sum += i;
            i--;
        }
        if (s1Sum != totalSum / 2)
        {
            vis[(totalSum / 2) - s1Sum] = 1;
            set1.push_back((totalSum / 2) - s1Sum);
        }
        for (ll i = 1; i < n; i++)
        {
            if (vis[i] == 0)
                set2.push_back(i);
        }
        cout << set1.size() << endl;
        for (auto it : set1)
            cout << it << " ";
        cout << endl;
        cout << set2.size() << endl;
        for (auto it : set2)
            cout << it << " ";
    }
}