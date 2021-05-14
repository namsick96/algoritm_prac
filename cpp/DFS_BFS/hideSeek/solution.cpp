#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int map[100000];

int bfs(int M, int N)
{
    if (N == M)
    {
        return 0;
    }
    int cnt = 0;
    queue<int> q;
    int target = M;
    q.push(M);
    while (map[N] == 0)
    {
        vector<int> tempq;
        cnt++;
        while (!q.empty())
        {
            int popped;
            popped = q.front();
            q.pop();
            int popped1 = popped - 1;
            int popped2 = popped + 1;
            int popped3 = 2 * popped;
            if (popped1 >= 0 && map[popped1] == 0)
            {
                map[popped1] = cnt;
                tempq.push_back(popped1);
            }
            if (popped2 <= 100000 && map[popped2] == 0)
            {
                map[popped2] = cnt;
                tempq.push_back(popped2);
            }
            if (popped3 <= 100000 && map[popped3] == 0)
            {
                map[popped3] = cnt;
                tempq.push_back(popped3);
            }
        }
        for (int i = 0; i < tempq.size(); i++)
        {
            q.push(tempq[i]);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, N;
    cin >> M >> N;
    int ans;
    ans = bfs(M, N);
    cout << ans;
}