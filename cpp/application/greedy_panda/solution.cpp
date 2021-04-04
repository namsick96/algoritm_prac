#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[500][500];
long long DP[500][500];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int x, int y, int iternum)
{

    if (DP[x][y] == -1)
    {
        DP[x][y] = 1;
        int temp = 0;
        for (int k = 0; k < 4; k++)
        {
            int newy = y + dy[k];
            int newx = x + dx[k];
            if (newy >= 0 && newy < iternum && newx >= 0 && newx < iternum && map[newx][newy] > map[x][y])
            {
                temp = max(temp, dfs(newx, newy, iternum));
            }
        }
        DP[x][y] += temp;
    }
    return DP[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iternum;
    cin >> iternum;
    for (int i = 0; i < iternum; i++)
    {
        for (int j = 0; j < iternum; j++)
        {
            cin >> map[i][j];
            DP[i][j] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < iternum; i++)
    {
        for (int j = 0; j < iternum; j++)
        {
            ans = max(ans, dfs(i, j, iternum));
        }
    }
    cout << ans;
}