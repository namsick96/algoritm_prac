#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iternum;
    cin >> iternum;

    int wine[iternum + 1];
    for (int i = 1; i < iternum + 1; i++)
    {
        int get;
        cin >> get;
        wine[i] = get;
    }

    long long house[iternum + 1];
    house[0] = 0;
    house[1] = wine[1];
    if (iternum >= 2)
    {
        house[2] = wine[1] + wine[2];
    }
    for (int k = 3; k < iternum + 1; k++)
    {
        long long temp;
        temp = max(house[k - 1], max(house[k - 2] + wine[k], house[k - 3] + wine[k] + wine[k - 1]));
        house[k] = temp;
    }
    cout << house[iternum];
    // 0 6 10 13 9 8 1
    // 0 6 16 23 28 31 33

    return 0;
}