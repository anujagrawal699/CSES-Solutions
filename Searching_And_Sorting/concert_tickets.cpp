#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<int> price;
    vector<int> customer(m);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        price.insert(p);
    }

    for (auto &it : customer)
        cin >> it;

    for (auto it : customer)
    {
        auto match = price.upper_bound(it);
        if (match == price.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --match;
            cout << *match << '\n';
            price.erase(match);
        }
    }

    return 0;
}