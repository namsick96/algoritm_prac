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
    int pointArr[iternum + 1];
    for (int i = 1; i < iternum + 1; i++)
    {
        int temp;
        cin >> temp;
        pointArr[i] = temp;
    }

    //if input ==1 인 경우 따로 빼주기
    if (iternum == 1)
    {
        cout << pointArr[1];
        return 0;
    }
    // 11
    // 12
    // 21
    // 22

    //if input>=2
    int house[iternum + 1][3][3];
    house[1][2][1] = pointArr[1];
    house[1][1][1] = -100;
    house[1][1][2] = -100;
    house[1][2][2] = -100;

    house[2][1][1] = pointArr[1] + pointArr[2];
    house[2][1][2] = pointArr[2];
    house[2][2][1] = -100;
    house[2][2][2] = -100;
    for (int p = 3; p < iternum + 1; p++)
    {
        //1 마지막
        house[p][2][1] = max(house[p - 1][1][2] + pointArr[p], house[p - 1][2][2] + pointArr[p]);
        house[p][1][1] = 0;
        //2 마지막
        house[p][1][2] = max(house[p - 2][2][1] + pointArr[p], house[p - 2][1][1] + pointArr[p]);
        house[p][2][2] = max(house[p - 2][2][2] + pointArr[p], house[p - 2][1][2] + pointArr[p]);
    }
    int ans = max(house[iternum][2][2], max(house[iternum][2][1], max(house[iternum][1][1], house[iternum][1][2])));
    cout << ans;
    /*for (int i = 2; i < iternum + 1; i++)
    {
        cout << i << endl;
        cout << house[i][1][1] << endl;
        cout << house[i][1][2] << endl;
        cout << house[i][2][1] << endl;
        cout << house[i][2][2] << endl;
    }
*/
    return 0;
}