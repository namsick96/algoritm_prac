#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
int map[1000][1000];
bool visited[1000][1000][2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int N, M;

int bfs()
{
    visited[0][0][0] = 1;
    pair<pair<int, int>, pair<int, int> > elem = make_pair(make_pair(0, 0), make_pair(1, 0));
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(elem);
    while (!q.empty())
    {
        pair<pair<int, int>, pair<int, int> > popped = q.front();
        q.pop();
        int y = popped.first.first;
        int x = popped.first.second;
        int cnt = popped.second.first;
        int isBreak = popped.second.second;

        if (y == N - 1 && x == M - 1)
        {
            return cnt;
        }

        for (int k = 0; k < 4; k++)
        {
            int newx = x + dx[k];
            int newy = y + dy[k];
            if (newy >= 0 && newy < N && newx >= 0 && newx < M)
            {
                if (map[newy][newx] == 1 && isBreak == 0)
                {
                    pair<pair<int, int>, pair<int, int> > newelem = make_pair(make_pair(newy, newx), make_pair(cnt + 1, 1));
                    q.push(newelem);
                    visited[newy][newx][1] = true;
                }
                else if (map[newy][newx] == 0 && visited[newy][newx][isBreak] == false)
                {
                    visited[newy][newx][isBreak] = true;
                    pair<pair<int, int>, pair<int, int> > newelem = make_pair(make_pair(newy, newx), make_pair(cnt + 1, isBreak));
                    q.push(newelem);
                }
            }
        }
        // if (newcount == 100)
        // {
        //     break;
        // }
    }
    return -1;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    int ans = bfs();
    cout << ans;
}