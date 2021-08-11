#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 9999999

using namespace std;

int map[101][101];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            map[i][j] = INF;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
            {
                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (map[a][b] > c)
        {
            map[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 0 or map[i][j] == INF)
            {
                cout << "0";
            }
            else
            {
                cout << map[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}