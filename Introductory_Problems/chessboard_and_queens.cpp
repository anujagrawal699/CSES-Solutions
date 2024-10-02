#include <iostream>
#include <set>
#include <cmath>

using namespace std;
#define repeat(i, s, e) for (int i = s; i < e; i++)

int ans;
set<pair<int, int>> reserved;
set<pair<int, int>> queens;

bool checkSQ(int x, int y)
{
    if (reserved.find({x, y}) != reserved.end())
    {
        return false;
    }
    for (auto &it : queens)
    {
        int i = it.first, j = it.second;
        if (i == x || j == y || i + j == x + y || i - j == x - y)
        {
            return false;
        }
    }
    return true;
}

void countCombinations(int r)
{
    if (r == 8)
    {
        ans++;
        return;
    }
    repeat(c, 0, 8)
    {
        if (checkSQ(r, c))
        {
            queens.insert({r, c});
            countCombinations(r + 1);
            queens.erase({r, c});
        }
    }
}

int main()
{
    repeat(i, 0, 8)
    {
        repeat(j, 0, 8)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                reserved.insert({i, j});
            }
        }
    }
    countCombinations(0);
    cout << ans << '\n';
}