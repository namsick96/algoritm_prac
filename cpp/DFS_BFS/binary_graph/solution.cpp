#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define RED 1
#define Blue 2
int V;
int E;
vector<int> map[20001]; //인접 행렬 그래프
int visited[20001];     //정점 방문 여부

void bfs(int first)
{
    queue<int> q;
    q.push(first);
    int color = RED;
    visited[first] = color;
    while (!q.empty())
    {
        int popped = q.front();
        q.pop();

        if (visited[popped] == RED)
        {
            color = Blue;
        }
        else if (visited[popped] == Blue)
        {
            color = RED;
        }

        for (int i = 0; i < map[popped].size(); i++)
        {
            if (visited[map[popped][i]] == 0)
            {
                visited[map[popped][i]] = color;
                q.push(map[popped][i]);
            }
        }
    }
}

bool isBi()
{
    for (int i = 1; i <= V; i++)
    {
        int gsize = map[i].size();
        for (int j = 0; j < gsize; j++)
        {
            int next = map[i][j];
            if (visited[i] == visited[next])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {

        cin >> V >> E;
        for (int q = 0; q < E; q++)
        {
            int start;
            int end;
            cin >> start >> end;
            map[start].push_back(end);
            map[end].push_back(start);
        }
        for (int q = 1; q <= V; q++)
        {
            if (!visited[q])
            { // 해당 노드를 아직 방문하지 않았다면,
                bfs(q);
            }
        }

        if (isBi())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        for (int q = 0; q <= V; q++)
        {
            map[q].clear();
        }
        memset(visited, false, sizeof(visited));
    }
}