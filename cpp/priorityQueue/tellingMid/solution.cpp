#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq_min;
priority_queue<int> pq_max;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arrlen;
    cin >> arrlen;

    int temp;
    cin >> temp;
    pq_max.push(temp);
    cout << temp << "\n";

    for (int k = 1; k < arrlen; k++)
    {
        int temp;
        cin >> temp;
        if (pq_max.size() > pq_min.size())
        {
            pq_min.push(temp);
        }
        else
        {
            pq_max.push(temp);
        }
        if (!pq_max.empty() && !pq_min.empty() && pq_max.top() > pq_min.top())
        {
            int temp1 = pq_max.top();
            pq_max.pop();
            int temp2 = pq_min.top();
            pq_min.pop();
            pq_max.push(temp2);
            pq_min.push(temp1);
        }
        cout << pq_max.top() << "\n";
    }
}