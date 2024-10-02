#include <iostream>
using namespace std;

long calculateWays(int K)
{
    long totalWays = ((long)K * K * (K * K - 1)) / 2;

    long attackingWays = 4 * (K - 1) * (K - 2);

    long ans = totalWays - attackingWays;

    return ans;
}

int main()
{
    int N;
    cin >> N;
    for (int K = 1; K <= N; K++)
    {
        cout << calculateWays(K) << " ";
    }

    return 0;
}
