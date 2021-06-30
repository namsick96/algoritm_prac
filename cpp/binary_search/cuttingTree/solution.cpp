#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<long> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int treeNum;
    long want;
    cin >> treeNum >> want;

    long maximum = 0;
    for (int k = 0; k < treeNum; k++)
    {
        long temp;
        cin >> temp;
        v.push_back(temp);
        maximum = max(maximum, temp);
    }
    long right = maximum;
    long left = 1;
    long answer = 0;
    while (left <= right)
    {
        long mid = (right + left) / 2;

        long temp = 0;
        for (int k = 0; k < treeNum; k++)
        {
            if (v[k] > mid)
            {
                temp = temp + v[k] - mid;
            }
            //temp = temp + v[k] - mid;
        }
        if (temp < want)
        {
            right = mid - 1;
        }
        else
        {
            if (answer < mid)
            {
                answer = mid;
            }
            left = mid + 1;
        }
    }
    cout << answer;
}