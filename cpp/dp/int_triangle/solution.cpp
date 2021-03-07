#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    //io check
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iternum;
    cin >> iternum;

    int root;
    cin >> root;

    int house[iternum + 1];
    house[0] = 0;
    house[1] = root;
    int before[iternum + 1];
    before[1] = root;
    before[0] = 0;

    for (int k = 2; k < iternum + 1; k++)
    {
        int temp[k + 1];
        for (int p = 1; p < k + 1; p++)
        {
            cin >> temp[p];
        }
        for (int q = 1; q < k + 1; q++)
        {
            if (q == 1)
            {
                house[q] = before[q] + temp[q];
            }
            else if (q == k)
            {
                house[q] = before[q - 1] + temp[q];
            }
            else
            {
                int survived;
                survived = max(before[q - 1] + temp[q], before[q] + temp[q]);
                house[q] = survived;
            }
        }

        for (int t = 1; t < k + 1; t++)
        {
            before[t] = house[t];
        }
    }
    int maximum = 0;
    for (int s = 1; s < iternum + 1; s++)
    {
        maximum = max(maximum, house[s]);
    }
    cout << maximum;
    return 0;
}