#include <iostream>
#include <vector>
#include <string>
#define ll long long

using namespace std;

int main()
{
    ll q;
    cin >> q;
    vector<ll> queries(q);
    for (auto &it : queries)
        cin >> it;

    vector<ll> pow10(19, 1);
    for (ll i = 1; i < 19; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
    for (ll query : queries)
    {
        ll digitsSoFar = 0;
        ll digitBefore = 0;
        ll numOfDigits;
        for (ll i = 1; i < 19; i++)
        {
            digitsSoFar += (pow10[i] - pow10[i - 1]) * i;
            if (digitsSoFar >= query)
            {
                numOfDigits = i;
                break;
            }
            digitBefore = digitsSoFar;
        }
        ll smallestValue = pow10[numOfDigits - 1];
        ll largestValue = pow10[numOfDigits] - 1;
        ll bestValue = 0;
        ll startOfBestValue;
        while (smallestValue <= largestValue)
        {
            ll actualvalue = (smallestValue + largestValue) / 2;
            ll startOfActualValue = digitBefore + 1 + (actualvalue - pow10[numOfDigits - 1]) * numOfDigits;
            if (startOfActualValue <= query)
            {
                if (actualvalue > bestValue)
                {
                    bestValue = actualvalue;
                    startOfBestValue = startOfActualValue;
                }
                smallestValue = actualvalue + 1;
            }
            else
                largestValue = actualvalue - 1;
        }
        string number = to_string(bestValue);
        cout << number[query - startOfBestValue] << '\n';
    }
}