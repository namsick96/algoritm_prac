#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int inlen;
    int iterlen;
    cin >> inlen;
    cin >> iterlen;

    int arr[inlen];
    int sumarr[inlen + 1];
    sumarr[0] = 0;
    int sumup = 0;

    for (int k = 0; k < inlen; k++)
    {
        int a;
        cin >> a;
        arr[k] = a;
        sumup = sumup + a;
        sumarr[k + 1] = sumup;
    }

    for (int k = 0; k < iterlen; k++)
    {
        int first, last, ans;
        cin >> first;
        cin >> last;
        ans = sumarr[last] - sumarr[first - 1];
        cout << ans << "\n";
    }
    return 0;
}