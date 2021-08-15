#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define INF 999999999
#define VERTEX 2001
using namespace std;

long long testCase, n, m, t;
long long s, g, h;
long long dest_possible[100];
vector<pair<long long, long long> > adj[VERTEX];
long long dist1[VERTEX];
long long dist2[VERTEX];
long long dist3[VERTEX];
long long branch = 0;

void Initialize()
{
    for (int i = 0; i < VERTEX; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < 100; i++)
    {
        dest_possible[i] = 0;
    }
}

void dj(long long start, long long dist[VERTEX])
{
    for (int k = 1; k < VERTEX; k++)
    {
        dist[k] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;

    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        long long cost = pq.top().first;
        long long cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
        {
            continue;
        }

        for (int k = 0; k < adj[cur].size(); k++)
        {
            long long nextCost = adj[cur][k].first;
            long long next = adj[cur][k].second;
            if (dist[next] > cost + nextCost)
            {
                dist[next] = cost + nextCost;
                pq.push(make_pair(dist[next], next));
                //cout << dist[next] << endl;
            }
        }
    }
}

void Solve()
{
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for (int k = 0; k < m; k++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back(make_pair(d, b));
        adj[b].push_back(make_pair(d, a));
        //cout << a << b << d << endl;
        if ((a == g and b == h) or (a == h and b == g))
        {
            branch = d;
        }
    }
    for (int k = 0; k < t; k++)
    {
        int x;
        cin >> x;
        dest_possible[k] = x;
    }
    dj(s, dist1);
    dj(h, dist2);
    dj(g, dist3);

    vector<int> answer;
    for (int k = 0; k < t; k++)
    {
        int tempDest = dest_possible[k];
        long long d1Dest = dist1[tempDest];
        long long d2Dest = dist1[g] + branch + dist2[tempDest];
        long long d3Dest = dist1[h] + branch + dist3[tempDest];
        if (d1Dest == d2Dest or d1Dest == d3Dest)
        {
            answer.push_back(tempDest);
        }
        else
        {
            continue;
        }
    }
    sort(answer.begin(), answer.end());

    for (int k = 0; k < answer.size(); k++)
    {
        cout << answer[k] << " ";
    }
    cout << "\n";
}

int main()
{
    cin >> testCase;
    for (int k = 0; k < testCase; k++)
    {
        Initialize();
        Solve();
    }
}