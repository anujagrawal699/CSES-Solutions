#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 1;

void update(int i, int j, int val, vector<pair<int, int>> &v, vector<int> &pos)
{
    int n = v.size();
    if (pos[i] > pos[j])
        swap(i, j);
    i = pos[i], j = pos[j];
    if (i > 0 && v[i - 1].second > v[i].second)
        ans += val;
    if (j < n - 1 && v[j].second > v[j + 1].second)
        ans += val;
    if (i + 1 == j)
    {
        if (v[i].second > v[j].second)
            ans += val;
    }
    else
    {
        if (i < n - 1 && v[i].second > v[i + 1].second)
            ans += val;
        if (j > 0 && v[j].second < v[j - 1].second)
            ans += val;
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    vector<int> pos(n);

    pos[v[0].second] = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second < v[i - 1].second)
            ans++;
        pos[v[i].second] = i;
    }
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        update(i, j, -1, v, pos);
        int k = pos[i], l = pos[j];
        swap(v[k].second, v[l].second);
        swap(pos[i], pos[j]);
        update(i, j, 1, v, pos);
        cout << ans << "\n";
    }
}