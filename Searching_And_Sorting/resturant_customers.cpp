#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b + 1, -1});
    }

    sort(events.begin(), events.end());

    int current = 0;
    int ans = 0;

    for (const auto &event : events)
    {
        current += event.second;
        ans = max(ans, current);
    }

    cout << ans << '\n';

    return 0;
}