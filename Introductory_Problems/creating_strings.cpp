#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve(int n, vector<string> &ans, unordered_map<char, int> mp, string temp)
{

    for (auto &it : mp)
    {
        if (it.second > 0)
        {
            temp.push_back(it.first);
            it.second--;
            solve(n, ans, mp, temp);
            temp.pop_back();
            it.second++;
        }
    }
    if (temp.size() == n)
    {
        ans.push_back(temp);
    }
}

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    int n = s.size();
    for (char c : s)
    {
        mp[c]++;
    }
    vector<string> ans;
    solve(n, ans, mp, "");
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (string st : ans)
    {
        cout << st << endl;
    }
}