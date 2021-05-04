#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int map[100][100];
int check[100][100];
bool visited[100][100];

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    int cntNum = 0;
    queue<pair<int, int> > q;
    pair<int, int> idx = make_pair(0, 0);
    q.push(idx);
    visited[0][0] = true;
    check[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> popped = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int newy = popped.first + dy[k];
            int newx = popped.second + dx[k];

            if (newx >= 0 && newy >= 0 && newx < M && newy < N)
            {
                if (map[newy][newx] == 1 && visited[newy][newx] == false)
                {
                    pair<int, int> newidx = make_pair(newy, newx);
                    q.push(newidx);
                    check[newy][newx] = check[popped.first][popped.second] + 1;
                    visited[newy][newx] = true;
                    //cout << newy << " " << newx << endl;
                }
            }
            if (newy == N - 1 && newx == M - 1)
            {
                return;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            scanf("%1d", &map[y][x]);
        }
    }
    bfs();
    cout << check[N - 1][M - 1];
}