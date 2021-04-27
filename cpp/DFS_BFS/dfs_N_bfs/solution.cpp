#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void dfs(int v, vector<int> map[], bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < map[v].size(); i++)
    {
        if (visited[map[v][i]] == false)
        {
            dfs(map[v][i], map, visited);
        }
    }
}
void bfs(int v, vector<int> map[], bool visited2[])
{
    queue<int> q;
    q.push(v);
    visited2[v] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < map[x].size(); i++)
        {
            int y = map[x][i];
            if (visited2[y] == false)
            {
                visited2[y] = true;
                q.push(y);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, V; //정점개수, 간선개수, 시작정점
    cin >> N >> M >> V;

    vector<int> map[N + 1]; //인접 행렬 그래프
    bool visited[N + 1];    //정점 방문 여부

    fill(visited, visited + N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(map[i].begin(), map[i].end());
    }

    dfs(V, map, visited);
    cout << endl;
    bool visited2[N + 1];
    fill(visited2, visited2 + N + 1, false);
    bfs(V, map, visited2);
    return 0;
}