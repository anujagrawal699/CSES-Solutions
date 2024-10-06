#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    bool flag = false;
    int c, d;
    while (i < j)
    {
        if (v[i].first + v[j].first == x)
        {
            flag = true;
            c = v[i].second;
            d = v[j].second;
            break;
        }
        else if (v[i].first + v[j].first > x)
        {
            j--;
        }
        else
            i++;
    }
    if (flag)
    {
        cout << c << " " << d;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    cout << "\n";
}