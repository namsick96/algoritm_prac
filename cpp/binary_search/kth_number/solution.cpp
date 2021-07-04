#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

long N;
long k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> k;
    long left = 1;
    long right = k;
    long result = 0;
    while (left <= right)
    {
        long mid = (left + right) / 2;
        long cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(mid / i, N);
        }
        if (cnt >= k)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << result;
}