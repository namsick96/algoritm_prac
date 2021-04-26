#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arrnum;
    cin >> arrnum;

    long long arr[arrnum];
    long long dp[arrnum];
    long long maximum;

    for (int k = 0; k < arrnum; k++)
    {
        cin >> arr[k];
    }

    maximum = arr[0];
    dp[0] = arr[0];

    for (int k = 1; k < arrnum; k++)
    {
        dp[k] = max((dp[k - 1] + arr[k]), arr[k]);

        maximum = max(dp[k], maximum);
    }
    /*
    for (int k = 0; k < arrnum; k++)
    {
        cout << dp[k] << endl;
    }
    */
    cout << maximum;
}