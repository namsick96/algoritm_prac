#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    //io check
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iternum;
    cin >> iternum;

    int house[iternum + 1][3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    int cost[3];
    for (int i = 1; i < iternum + 1; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];
    }
    cout << min(house[iternum][0], min(house[iternum][1], house[iternum][2]));
    return 0;
}