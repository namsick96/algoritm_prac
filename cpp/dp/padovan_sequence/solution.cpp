#include <iostream>
using namespace std;

int main()
{
    //io check
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iternum;
    cin >> iternum;

    int maxnum = 0;
    int inArr[iternum];
    for (int i = 0; i < iternum; i++)
    {
        int temp;
        cin >> temp;
        maxnum = max(maxnum, temp);
        inArr[i] = temp;
    }

    long long ansArr[maxnum + 1];
    if (maxnum <= 3)
    {
        for (int k = 1; k < maxnum + 1; k++)
        {
            ansArr[k] = 1;
        }
    }
    else
    {
        ansArr[1] = 1;
        ansArr[2] = 1;
        ansArr[3] = 1;
        for (int q = 4; q < maxnum + 1; q++)
        {
            ansArr[q] = ansArr[q - 2] + ansArr[q - 3];
        }
    }

    for (int p = 0; p < iternum; p++)
    {
        cout << ansArr[inArr[p]] << "\n";
    }

    for (int tt = 0; tt < maxnum + 1; tt++)
    {
        cout << ansArr[tt] << "\n";
    }

    // p1=1
    // p2=1
    // p3=1
    // p4=2
    // p5=2
    // p6=3
    // p7=4
    // p8=5
    // p9=7
    // p10=9
    // p11=12

    return 0;
}