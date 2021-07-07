#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arrlen;
    cin >> arrlen;
    for (int k = 0; k < arrlen; k++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(make_pair(abs(temp), temp));
        }
    }
}