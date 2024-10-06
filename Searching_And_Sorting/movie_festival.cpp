#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movies.push_back({b, a});
    }
    sort(movies.begin(), movies.end());
    int ans = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (movies[i].second >= end)
        {
            ans++;
            end = movies[i].first;
        }
    }
    cout << ans << '\n';
}