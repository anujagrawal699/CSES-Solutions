#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (auto &it : p)
        cin >> it;
    sort(p.begin(), p.end());
    int gondala = 0;
    int i = 0, j = n - 1;
    while (p[j] + p[i] > x && j >= 0)
    {
        j--;
        gondala++;
    }
    while (i <= j)
    {
        if (p[i] + p[j] <= x)
        {
            i++;
        }
        j--;
        gondala++;
    }
    cout << gondala << endl;
}