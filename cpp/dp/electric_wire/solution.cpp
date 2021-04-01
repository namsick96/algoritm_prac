#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iternum;
    cin >> iternum;

    int side[501] = {
        0,
    };
    int DP[iternum];
    for (int k = 0; k < iternum; k++)
    {
        int atemp;
        int btemp;
        cin >> atemp >> btemp;
        side[atemp] = btemp;
        DP[k] = 0;
    }

    int realArr[iternum];
    int idx = 0;
    for (int k = 0; k < 501; k++)
    {
        if (side[k] != 0)
        {
            realArr[idx] = side[k];
            idx++;
        }
    }

    int ans = 0;
    for (int k = 0; k < iternum; k++)
    {
        DP[k] = 1;
        int history = 0;
        for (int i = 0; i < k; i++)
        {
            if (realArr[i] < realArr[k])
            {
                history = max(history, DP[i]);
            }
        }
        DP[k] = history + 1;
        ans = max(ans, DP[k]);
    }
    ans = iternum - ans;
    cout << ans;

    //8 2 9 1 4 6 7 10
}