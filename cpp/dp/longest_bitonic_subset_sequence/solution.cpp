#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arrlen;
    cin >> arrlen;
    int arr[arrlen];
    int dp1[arrlen];
    int dp2[arrlen];

    for (int k = 0; k < arrlen; k++)
    {
        cin >> arr[k];
        dp1[k] = 0;
        dp2[k] = 0;
    }

    for (int k = 0; k < arrlen; k++)
    {
        if (dp1[k] == 0)
        {
            dp1[k] = 1;
        }
        for (int i = 0; i < k; i++)
        {
            if ((arr[k] > arr[i]) & (dp1[k] < dp1[i] + 1))
            {
                dp1[k] = dp1[i] + 1;
            }
        }
    }
    for (int k = arrlen - 1; k >= 0; k--)
    {
        if (dp2[k] == 0)
        {
            dp2[k] = 1;
        }
        for (int i = arrlen - 1; i > k; i--)
        {
            if ((arr[k] > arr[i]) & (dp2[k] < dp2[i] + 1))
            {
                dp2[k] = dp2[i] + 1;
            }
        }
    }
    int ans[arrlen];
    int maxim = 0;
    for (int k = 0; k < arrlen; k++)
    {
        int temp = 0;
        temp = dp1[k] + dp2[k] - 1;
        maxim = max(temp, maxim);
        // cout << dp1[k] << " " << dp2[k] << endl;
    }
    cout << maxim;
}