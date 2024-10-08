#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    ll sum = 0;
    ll maxi = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    cout << maxi << endl;
}