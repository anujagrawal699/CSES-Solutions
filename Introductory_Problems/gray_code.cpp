#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solve(int n)
{
    if (n == 1)
    {
        return {"0", "1"};
    }

    vector<string> prev = solve(n - 1);

    vector<string> res;
    for (int i = 0; i < prev.size(); i++)
    {
        res.push_back("0" + prev[i]);
    }
    for (int i = prev.size() - 1; i >= 0; i--)
    {
        res.push_back("1" + prev[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = solve(n);
    for (auto it : ans)
    {
        cout << it << endl;
    }
}