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
    int arr[arrlen + 1];
    arr[0] = 0;
    int house[arrlen + 1];
    house[0] = 0;
    for (int i = 1; i < arrlen + 1; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i < arrlen + 1; i++)
    {
        int history = 0;
        for (int k = 1; k < i; k++)
        {
            if (arr[i] > arr[k])
            {
                history = max(history, house[k]);
            }
        }
        house[i] = history + 1;
        ans = max(ans, house[i]);
    }
    cout << ans << endl;
    // for (int i = 0; i < arrlen + 1; i++)
    // {
    //     cout << house[i] << endl;
    // }
}