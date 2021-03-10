#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target;
    cin >> target;

    int house[target + 3];
    house[1] = 0;
    house[2] = 1;
    house[3] = 1;
    int ans;
    for (int k = 4; k < target + 1; k++)
    {
        int temp = k;
        int div2 = target;
        int div3 = target;
        int minus1 = target;
        if (temp % 2 == 0)
        {
            div2 = house[k / 2] + 1;
        }
        if (temp % 3 == 0)
        {
            div3 = house[k / 3] + 1;
        }
        minus1 = house[k - 1] + 1;

        house[k] = min(div2, min(div3, minus1));
    }
    cout << house[target];
    return 0;
    /*for (int p = 1; p < target + 1; p++)
    {
        cout << house[p] << endl;

    }*/

    // 1 1
    // 2 1
    // 3 1
    // 4 2
    // 5 3
    // 6 2
    // 7 3
    // 8 3
    // 9 2
    // 10 4
    // 11 5
    // 12 3
}