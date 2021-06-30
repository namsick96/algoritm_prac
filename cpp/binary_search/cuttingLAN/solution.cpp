#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v_size;
    long lan_num;
    long maxtemp = 0;
    cin >> v_size >> lan_num;
    for (int k = 0; k < v_size; k++)
    {
        long temp;
        cin >> temp;
        v.push_back(temp);
        maxtemp = max(maxtemp, temp);
    }

    long left = 1;
    long right = maxtemp;
    long answer = 0;
    while (left <= right)
    {
        long temp = 0;
        long mid = (left + right) / 2;
        for (int i = 0; i < v_size; i++)
        {
            temp = temp + (v[i] / mid);
        }
        if (temp < lan_num)
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