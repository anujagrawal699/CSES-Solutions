#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if ((2 * a - b) % 3 || (2 * a - b) < 0 || (2 * b - a) % 3 || (2 * b - a) < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}