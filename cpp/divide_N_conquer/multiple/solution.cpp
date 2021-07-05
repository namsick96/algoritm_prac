#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

long long pow(long long x, long long y, long long z)
{
    long long temp;
    if (y == 0)
    {
        return 1;
    }
    else
    {
        temp = pow(x, y / 2, z);
    }
    temp = temp * temp % z;
    if (y % 2 == 1)
    {
        temp = (temp * x) % z;
    }
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double A, B, C;
    cin >> A >> B >> C;

    long long answer = pow(A, B, C);
    cout << answer;
}