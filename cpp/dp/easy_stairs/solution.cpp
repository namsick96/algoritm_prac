#include <iostream>
#define MOD 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    cin >> target;

    int house[target + 1][11];
    for (int i = 1; i < 10; i++)
    {
        house[1][i] = 1;
    }
    house[1][0] = 0;
    house[1][10] = 0;

    for (int k = 2; k < target + 1; k++)
    {
        for (int p = 0; p < 11; p++)
        {
            if (p == 0)
            {
                house[k][p] = house[k - 1][1] % MOD;
            }
            else if (p == 10)
            {
                house[k][p] = 0;
            }
            else
            {
                house[k][p] = (house[k - 1][p - 1] + house[k - 1][p + 1]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int q = 0; q < 11; q++)
    {
        ans = (ans + house[target][q]) % MOD;
    }
    cout << ans % MOD;

    return 0;
}