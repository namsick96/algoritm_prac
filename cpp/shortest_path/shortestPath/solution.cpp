#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 9999999
#define VERTEX 20001
#define EDGE 300001

using namespace std;

vector<pair<int, int> > adj[VERTEX];
int Ecount;
int Vcount;
int start;
int dist[VERTEX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> Vcount >> Ecount >> start;
    for (int i = 0; i < Ecount; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }

    for (int i = 1; i <= Vcount; i++)
    {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < cost)
        {
            continue;
        }

        for (int i = 0; i < adj[current].size(); i++)
        {
            int nextCost = adj[current][i].first;
            int next = adj[current][i].second;

            if (dist[next] > cost + nextCost)
            {
                dist[next] = cost + nextCost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    for (int i = 1; i <= Vcount; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}