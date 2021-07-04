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

    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (v.size() == 0)
        {
            v.push_back(temp);
        }
        else
        {
            if (v.back() < temp)
            {
                v.push_back(temp);
            }
            else
            {
                vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
                *low = temp;
            }
        }
    }
    cout << v.size();
}