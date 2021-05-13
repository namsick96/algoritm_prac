#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int cntNum = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N;

void bfs(queue<pair<int, int> > idxPair)
{
    while (!idxPair.empty())
    {
        queue<pair<int, int> > tempPair;
        while (!idxPair.empty())
        {
            pair<int, int> popped = idxPair.front();
            idxPair.pop();
            int y = popped.first;
            int x = popped.second;
            for (int i = 0; i < 4; i++)
            {
                int newy = y + dy[i];
                int newx = x + dx[i];
                if (newy >= 0 && newy < M && newx >= 0 && newx < N)
                {
                    if (map[newy][newx] == 0)
                    {
                        map[newy][newx] = 1;
                        tempPair.push(make_pair(newy, newx));
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
    cin >> M >> N;

    for (int k = 0; k < N; k++)
    {
        for (int p = 0; p < M; p++)
        {
            cin >> map[p][k];
        }
    }
    queue<pair<int, int> > idxPair;
    for (int k = 0; k < N; k++)
    {
        for (int p = 0; p < M; p++)
        {
            if (map[p][k] == 1)
            {
                idxPair.push(make_pair(p, k));
            }
        }
    }
    bfs(idxPair);
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
    for (int k = 0; k < N; k++)
    {
        for (int p = 0; p < M; p++)
        {
            if (map[p][k] == 0)
            {
                cout << -1;
                return 0;
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