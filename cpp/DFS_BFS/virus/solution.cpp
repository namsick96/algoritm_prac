#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void dfs(int v, vector<int> map[], bool visited[])
{
    visited[v] = true;
    for (int i = 0; i < map[v].size(); i++)
    {
        if (visited[map[v][i]] == false)
        {
            dfs(map[v][i], map, visited);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, V; //정점개수, 간선개수, 시작정점
    cin >> N >> M;
    V = 1;
    vector<int> map[N + 1];
    bool visited[N + 1];
    fill_n(visited, N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        map[start].push_back(end);
        map[end].push_back(start);
    }
    dfs(V, map, visited);
    int summation = 0;
    for (int i = 0; i < N + 1; i++)
    {
        //cout << visited[i] << endl;
        if (visited[i] == true)
        {
            summation++;
        }
    }
    cout << summation - 1;
}