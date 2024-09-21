#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char &it : s)
        mp[it]++;
    int odd = 0;
    char odd_char;
    int odd_char_freq = 0;
    for (auto it : mp)
    {
        if (it.second % 2)
        {
            odd++;
            odd_char = it.first;
            odd_char_freq = it.second;
        }
        if (odd > 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    string temp = "";
    for (auto it : mp)
    {
        if (it.second % 2 == 0)
        {
            for (int i = 0; i < it.second / 2; i++)
            {
                temp += it.first;
            }
        }
    }
    string ans = temp;

    reverse(temp.begin(), temp.end());
    if (odd != 0)
    {
        for (int i = 0; i < odd_char_freq; i++)
        {
            ans += odd_char;
        }
    }
    cout << ans + temp << endl;
}