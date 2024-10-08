#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int ans = 0;
    set<int> s;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && s.find(v[j]) == s.end())
        {
            s.insert(v[j]);
            j++;
        }
        ans = max(ans, j - i);
        if (j == n)
            break;
        s.erase(v[i]);
    }
    cout << ans << "\n";
}