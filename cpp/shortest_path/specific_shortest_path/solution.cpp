#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 99999999
#define VERTEX 801
#define EDGE 200001

using namespace std;

long long dist[VERTEX];
vector<pair<int, int> > adj[VERTEX];
int N, E;

void init_dist(int startIdx)
{
    for (int k = 1; k < VERTEX; k++)
    {
        dist[k] = INF;
    }
    dist[startIdx] = 0;
}

int dijkstra(int from, int to)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    init_dist(from);
    pq.push(make_pair(0, from));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
        {
            continue;
        }
        for (int k = 0; k < adj[cur].size(); k++)
        {
            int next = adj[cur][k].second;
            int nextCost = adj[cur][k].first;
            if (dist[next] > cost + nextCost)
            {
                dist[next] = cost + nextCost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }

    int temp = dist[to];
    if (temp == INF)
    {
        return -1;
    }
    else
    {
        return temp;
    }
}
//     answer = answer + temp1;
//     init_dist(edge1);
//     pq.push(make_pair(0, edge1));

//     while (!pq.empty())
//     {
//         int cost = pq.top().first;
//         int cur = pq.top().second;
//         pq.pop();

//         if (dist[cur] < cost)
//         {
//             continue;
//         }
//         for (int k = 0; k < adj[cur].size(); k++)
//         {
//             int next = adj[cur][k].second;
//             int nextCost = adj[cur][k].first;
//             if (dist[next] > cost + nextCost)
//             {
//                 dist[next] = cost + nextCost;
//                 pq.push(make_pair(dist[next], next));
//             }
//         }
//     }

//     int temp2 = dist[edge2];
//     if (temp2 == INF)
//     {
//         cout << -1;
//         return 0;
//     }
//     else
//     {
//         answer = answer + dist[edge2];
//     }

//     init_dist(edge2);
//     pq.push(make_pair(0, edge2));
//     while (!pq.empty())
//     {
//         int cur = pq.top().second;
//         int cost = pq.top().first;
//         pq.pop();
//         if (dist[cur] < cost)
//         {
//             continue;
//         }
//         for (int k = 0; k < adj[cur].size(); k++)
//         {
//             int next = adj[cur][k].second;
//             int nextCost = adj[cur][k].first;
//             if (dist[next] > cost + nextCost)
//             {
//                 dist[next] = cost + nextCost;
//                 pq.push(make_pair(dist[next], next));
//             }
//         }
//     }
//     int temp3 = dist[N];
//     if (temp3 == INF)
//     {
//         cout << -1;
//         return 0;
//     }
//     else
//     {
//         answer = answer + dist[N];
//         cout << answer;
//         return 0;
//     }
// }

int main()
{
    cin >> N >> E;
    for (int k = 0; k < E; k++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    int get1, get2;
    cin >> get1 >> get2;

    //CASE1
    bool CASE1bool = false;
    int answer1 = 0;
    int temp1 = dijkstra(1, get1);
    if (temp1 == -1)
    {
        CASE1bool = true;
    }
    else
    {
        answer1 = answer1 + temp1;
    }
    int temp2 = dijkstra(get1, get2);
    if (temp2 == -1)
    {
        CASE1bool = true;
    }
    else
    {
        answer1 = answer1 + temp2;
    }
    int temp3 = dijkstra(get2, N);
    if (temp3 == -1)
    {
        CASE1bool = true;
    }
    else
    {
        answer1 = answer1 + temp3;
    }

    //CASE2
    bool CASE2bool = false;
    int answer2 = 0;
    int temp4 = dijkstra(1, get2);
    if (temp4 == -1)
    {
        CASE2bool = true;
    }
    else
    {
        answer2 = answer2 + temp4;
    }
    int temp5 = dijkstra(get2, get1);
    if (temp5 == -1)
    {
        CASE2bool = true;
    }
    else
    {
        answer2 = answer2 + temp5;
    }
    int temp6 = dijkstra(get1, N);
    if (temp6 == -1)
    {
        CASE2bool = true;
    }
    else
    {
        answer2 = answer2 + temp6;
    }

    // cout << temp1 << endl
    //      << temp2 << endl
    //      << temp3 << endl
    //      << temp4 << endl
    //      << temp5 << endl
    //      << temp6 << endl;
    //print
    if (CASE1bool and CASE2bool)
    {
        cout << -1;
    }
    else
    {
        if (!CASE1bool and CASE2bool)
        {
            cout << answer1;
        }
        else if (CASE1bool and !CASE2bool)
        {
            cout << answer2;
        }
        else if (!CASE1bool and !CASE2bool)
        {
            cout << min(answer1, answer2);
        }
    }
}