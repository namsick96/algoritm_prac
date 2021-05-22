#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int map[100][100][100];
bool visited[100][100][100];
int cntNum = 0;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;

void bfs(queue<pair<int, pair<int, int> > > idxPair)
{
    while (!idxPair.empty())
    {
        queue<pair<int, pair<int, int> > > tempPair;
        while (!idxPair.empty())
        {
            pair<int, pair<int, int> > popped = idxPair.front();
            idxPair.pop();
            int z = popped.first;
            int y = popped.second.first;
            int x = popped.second.second;
            for (int i = 0; i < 6; i++)
            {
                int newz = z + dz[i];
                int newy = y + dy[i];
                int newx = x + dx[i];
                if (newy >= 0 && newy < M && newx >= 0 && newx < N && newz >= 0 && newz < H)
                {
                    if (map[newz][newy][newx] == 0)
                    {
                        map[newz][newy][newx] = 1;
                        tempPair.push(make_pair(newz, make_pair(newy, newx)));
                    }
                }
            }
        }
        if (!tempPair.empty())
        {
            cntNum++;
        }
        while (!tempPair.empty())
        {
            idxPair.push(tempPair.front());
            tempPair.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;

    for (int z = 0; z < H; z++)
    {
        for (int k = 0; k < N; k++)
        {
            for (int p = 0; p < M; p++)
            {
                cin >> map[z][p][k];
            }
        }
    }
    queue<pair<int, pair<int, int> > > idxPair;

    for (int z = 0; z < H; z++)
    {
        for (int k = 0; k < N; k++)
        {
            for (int p = 0; p < M; p++)
            {
                if (map[z][p][k] == 1)
                {
                    idxPair.push(make_pair(z, make_pair(p, k)));
                }
            }
        }
    }
    bfs(idxPair);

    for (int z = 0; z < H; z++)
    {
        for (int k = 0; k < N; k++)
        {
            for (int p = 0; p < M; p++)
            {
                if (map[z][p][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    /*
    for (int k = 0; k < N; k++)
    {
        for (int p = 0; p < M; p++)
        {
            cout << map[p][k];
        }
        cout << endl;
    }
    */
    cout << cntNum;
    return 0;
}