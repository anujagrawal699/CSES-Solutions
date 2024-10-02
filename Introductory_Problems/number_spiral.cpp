#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll y, x;
        ll num;
        cin >> y >> x;
        if (y > x)
        {
            if (y % 2 == 0)
            {
                num = (y * y) - x + 1;
            }
            else
            {
                num = ((y - 1) * (y - 1)) + 1 + x - 1;
            }
        }
        else
        {
            if (x % 2 == 1)
            {
                num = (x * x) - y + 1;
            }
            else
            {
                num = ((x - 1) * (x - 1)) + 1 + y - 1;
            }
        }
        cout << num << endl;
    }
}