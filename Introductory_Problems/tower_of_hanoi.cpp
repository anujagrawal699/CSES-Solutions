#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int start, int mid, int end, vector<pair<int, int>> &moves)
{
    if (n == 0)
        return;
    solve(n - 1, start, end, mid, moves);
    moves.push_back({start, end});
    solve(n - 1, mid, start, end, moves);
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    vector<pair<int, int>> moves;
    solve(n, 1, 2, 3, moves);
    for (auto it : moves)
    {
        cout << it.first << " " << it.second << endl;
    }
}