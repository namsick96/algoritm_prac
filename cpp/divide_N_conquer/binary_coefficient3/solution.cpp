#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define MOD 1000000007
using namespace std;

long long pow1(long long x, long long y)
{
    long long temp = 1;
    for (int k = x; k >= x - y + 1; k--)
    {
        temp = (temp * k) % MOD;
    }
    return temp;
}

long long pow2(long long x, long long y)
{
    long long temp;
    if (y == 0)
    {
        return 1;
    }
    else
    {
        temp = pow2(x, y / 2);
    }
    temp = temp * temp % MOD;
    if (y % 2 == 1)
    {
        temp = (temp * x) % MOD;
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    long long fore = pow1(A, B);
    long long temp2 = pow1(B, B);
    long long back = pow2(temp2, MOD - 2);
    cout << (fore * back) % MOD;
}