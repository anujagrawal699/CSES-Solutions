#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> permutation;
    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    int i = 2;

    while (i <= n)
    {
        permutation.push_back(i);
        i += 2;
    }
    i = 1;
    while (i <= n)
    {
        permutation.push_back(i);
        i += 2;
    }
    for (int i : permutation)
    {
        cout << i << " ";
    }
}