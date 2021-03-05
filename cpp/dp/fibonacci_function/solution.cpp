#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int iterlen;
    cin >> iterlen;

    int inNumArr[iterlen];
    int maxNum = 0;

    for (int k = 0; k < iterlen; k++)
    {
        int innum;
        cin >> innum;
        inNumArr[k] = innum;
        maxNum = max(maxNum, innum);
    }
    int fib0Arr[maxNum + 2];
    int fib1Arr[maxNum + 2];
    fib0Arr[0] = 1;
    fib0Arr[1] = 0;
    fib1Arr[0] = 0;
    fib1Arr[1] = 1;
    for (int p = 2; p < maxNum + 2; p++)
    {
        fib0Arr[p] = fib0Arr[p - 1] + fib0Arr[p - 2];
        fib1Arr[p] = fib1Arr[p - 1] + fib1Arr[p - 2];
    }

    for (int q = 0; q < (sizeof(inNumArr) / sizeof(int)); q++)
    {

        cout << fib0Arr[inNumArr[q]] << " ";
        cout << fib1Arr[inNumArr[q]] << "\n";
    }

    // int fib0arr[innum+1];
    // fib0arr[0]=1;
    // fib0arr[1]=0;
    // int fib1arr[innum+1];
    // fib1arr[0]=0;
    // fib

    // fib(2)=fib(1)+fib(0)
    // fib(4)=fib(3)+fib(2)=fib(2)+fib(1)+fib(1)+fib(0)=fib(1)+fib(0)+
    // fib(0) 1,0
    // fib 1  0 1
    // fib 2  1 1
    // fib 3  fib(2)+fib(1) >>fib 1+ fib0 +fib1 >> 1 2
    // fib 4 >> fib 3 + fib 2 >>> fib 1 + fib 0 + fib 1 + fib 1+ fib 0 >> 2 3

    return 0;
}