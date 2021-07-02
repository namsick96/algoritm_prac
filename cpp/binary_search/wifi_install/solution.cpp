#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<long> v;
int N;
int C;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    for (int k = 0; k < N; k++)
    {
        long temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    long mini = 1;
    long maxi = v[N - 1] - v[0];
    long left = mini;
    long right = maxi;
    long result = 0;
    while (left <= right)
    {
        long mid = (left + right) / 2;
        long cnt = 1;
        long prev = v[0];
        for (int k = 1; k < N; k++)
        {
            if (v[k] - prev >= mid)
            {
                prev = v[k];
                cnt++;
            }
        }
        if (cnt >= C)
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result;
}