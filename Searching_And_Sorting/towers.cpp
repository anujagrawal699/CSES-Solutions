#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0;
    map<int, int> s;
    for (int i : v)
    {
        auto it = s.upper_bound(i);
        if (it == s.end())
        {
            ans++;
            s[i]++;
        }
        else
        {
            s[it->first]--;

            if (s[it->first] == 0)
                s.erase(it->first);

            s[i]++;
        }
    }
    cout << ans << "\n";
}