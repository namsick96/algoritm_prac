#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 99999999
#define VERTEX 501
#define EDGE 6001
using namespace std;

vector<pair<long long, pair<long long, long long> > > edges;
long long dist[VERTEX];
int N, M;

bool bellman()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int cur_node = edges[j].first;
            int next_node = edges[j].second.first;
            int cost = edges[j].second.second;

            if (dist[cur_node] == INF)
            {
                continue;
            }
            long long nextCost = dist[cur_node] + cost;
            if (dist[next_node] > nextCost)
            {
                dist[next_node] = nextCost;
                if (i == N - 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> N >> M;

    for (int k = 0; k < M; k++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(a, make_pair(b, c)));
    }

    for (int k = 0; k <= 500; k++)
    {
        dist[k] = INF;
    }

    dist[1] = 0;
    bool check = bellman();
    if (check)
    {
        cout << "-1\n";
        return 0;
    }
    for (int k = 2; k <= N; k++)
    {

        if (dist[k] == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist[k] << "\n";
        }
    }
}