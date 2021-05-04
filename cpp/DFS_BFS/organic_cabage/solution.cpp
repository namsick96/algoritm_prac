#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

bool map[50][50];
bool visited[50][50];
int cntNum = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void reset()
{
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
}

void dfs(int p, int q)
{
    visited[p][q] = true;
    for (int k = 0; k < 4; k++)
    {
        int newp = p + dx[k];
        int newq = q + dy[k];

        if (newp >= 0 && newp < 50 && newq >= 0 && newq < 50)
        {
            if (map[newp][newq] == true && visited[newp][newq] == false)
            {
                dfs(newp, newq);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, M, N, K;
    cin >> T;
    int ans[T];

    for (int k = 0; k < T; k++)
    {
        cin >> M >> N >> K;
        for (int p = 0; p < K; p++)
        {
            int x;
            int y;
            cin >> x >> y;
            map[x][y] = true;
        }
        for (int p = 0; p < M; p++)
        {
            for (int q = 0; q < N; q++)
            {
                if (map[p][q] == true && visited[p][q] == false)
                {
                    dfs(p, q);
                    cntNum++;
                }
            }
        }
        ans[k] = cntNum;
        cntNum = 0;
        reset();
    }
    for (int k = 0; k < T; k++)
    {
        cout << ans[k] << '\n';
    }
}