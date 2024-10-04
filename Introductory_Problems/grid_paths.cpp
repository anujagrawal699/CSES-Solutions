#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
#define isValid(a, b, c) (a >= b && a < c ? 1 : 0)
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int ans = 0;
string s;
int vis[7][7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int solve(int r, int c, int pos)
{
    if (pos == 48)
    {
        return (r == 6 && c == 0);
    }
    if (r == 6 && c == 0)
    {
        return 0;
    }
    if (vis[r][c])
        return 0;
    vector<int> adjVis(4, -1);
    for (int k = 0; k < 4; k++)
    {
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (isValid(nr, 0, 7) && isValid(nc, 0, 7))
        {
            adjVis[k] = vis[nr][nc];
        }
    }
    if (adjVis[UP] && adjVis[DOWN] && !adjVis[LEFT] && !adjVis[RIGHT])
        return 0;
    if (adjVis[LEFT] && adjVis[RIGHT] && !adjVis[UP] && !adjVis[DOWN])
        return 0;
    if (isValid(r - 1, 0, 7) && isValid(c + 1, 0, 7) && vis[r - 1][c + 1])
    {
        if (!adjVis[UP] && !adjVis[RIGHT])
            return 0;
    }
    if (isValid(r + 1, 0, 7) && isValid(c + 1, 0, 7) && vis[r + 1][c + 1])
    {
        if (!adjVis[DOWN] && !adjVis[RIGHT])
            return 0;
    }
    if (isValid(r + 1, 0, 7) && isValid(c - 1, 0, 7) && vis[r + 1][c - 1])
    {
        if (!adjVis[DOWN] && !adjVis[LEFT])
            return 0;
    }
    if (isValid(r - 1, 0, 7) && isValid(c - 1, 0, 7) && vis[r - 1][c - 1])
    {
        if (!adjVis[UP] && !adjVis[LEFT])
            return 0;
    }
    vis[r][c] = 1;
    int paths = 0;
    if (s[pos] == '?')
    {
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (isValid(nr, 0, 7) && isValid(nc, 0, 7) && !vis[nr][nc])
            {
                paths += solve(nr, nc, pos + 1);
            }
        }
    }
    else
    {
        int k = 0;
        if (s[pos] == 'U')
            k = 0;
        if (s[pos] == 'R')
            k = 1;
        if (s[pos] == 'D')
            k = 2;
        if (s[pos] == 'L')
            k = 3;
        int nr = r + dx[k];
        int nc = c + dy[k];
        if (isValid(nr, 0, 7) && isValid(nc, 0, 7) && !vis[nr][nc])
        {
            paths += solve(nr, nc, pos + 1);
        }
    }
    vis[r][c] = 0;

    return paths;
}

int main()
{
    cin >> s;

    int ans = solve(0, 0, 0);
    cout << ans << endl;
}
