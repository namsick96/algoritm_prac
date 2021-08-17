#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>

#define INF 99999999
#define VERTEX 101
using namespace std;

int testCase;
int N, M, K;
vector<tuple<int, int, int> > adj[VERTEX];
int dist[VERTEX][10001];

void Initialize()
{
    for (int i = 0; i < VERTEX; i++)
    {
        adj[i].clear();
        for(int j=0; j<10001; j++){
            dist[i][j]=INF;
        }
        //dist[i].push_back(INF);
    }
    //dist[1].push_back(make_pair(0,0));
}

void Solve()
{
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;

        adj[u].push_back(make_tuple(v,c, d));
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    pq.push(make_tuple(0,0,1));
    while(!pq.empty()){
        int wait=get<0>(pq.top());
        int price=get<1>(pq.top());
        int cur=get<2>(pq.top());
        pq.pop();

        for(int k=0; k<adj[cur].size(); k++){
            int nextWait=get<2>(adj[cur][k]);
            int nextPrice=get<1>(adj[cur][k]);
            int next=get<0>(adj[cur][k]);
            
            if(price+nextPrice>M){
                continue;
            }
            else{
                if(dist[next][price+nextPrice]>wait+nextWait){
                    dist[next][price+nextPrice]=wait+nextWait;
                    pq.push(make_tuple(wait+nextWait,price+nextPrice,next));
                }
            }
        }
    }
    
    
    int answer=INF;
    for(int i=0; i<10001; i++){
        answer=min(answer,dist[N][i]);
    }
    if(answer==INF){
        cout<<"Poor KCM\n";
    }
    else{
        cout<<answer<<endl;
    }
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