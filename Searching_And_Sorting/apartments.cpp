#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), s(m);
    for (auto &it : a)
        cin >> it;
    for (auto &it : s)
        cin >> it;
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[j] >= a[i] - k && s[j] <= a[i] + k)
        {
            i++;
            j++;
            ans++;
        }
        else if (s[j] < a[i] - k)
        {
            j++;
        }
        else
            i++;
    }
    cout << ans << endl;
}