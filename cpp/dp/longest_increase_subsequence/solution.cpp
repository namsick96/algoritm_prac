#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arrlen;
    cin >> arrlen;

    long house[arrlen + 1];
    house[0] = 0;
    long arr[arrlen + 1];
    arr[0] = 0;

    for (int i = 1; i < arrlen + 1; i++)
    {
        long temp;
        cin >> temp;
        arr[i] = temp;
        house[i] = temp;
    }
    long answer = 0;
    for (int i = 1; i < arrlen + 1; i++)
    {
        long history = 0;
        for (int k = 1; k < i; k++)
        {
            if (arr[k] < arr[i])
            {
                history = max(history, house[k]);
            }
        }
        house[i] = history + arr[i];
        answer = max(answer, house[i]);
    }
    cout << answer;
}