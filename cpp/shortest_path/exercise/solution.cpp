#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 99999999
#define VERTEX 401
#define EDGE 200000
using namespace std;

int V, E;
int map[401][401];

int main()
{
    for (int i = 0; i < VERTEX; i++)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            if (i == j)
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = INF;
            }
        }
    }

    cin >> V >> E;
    for (int k = 0; k < E; k++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    long answer = INF;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (i == j)
            {
                continue;
            }
            long sumup = map[i][j] + map[j][i];
            answer = min(answer, sumup);
        }
    }
    if (answer >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}