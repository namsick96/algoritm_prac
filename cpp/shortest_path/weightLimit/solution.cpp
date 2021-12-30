#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;
int N,M;
vector<pair<int,int>> board[100001];
bool visited[100001];
int start,dest;
int max_cost;

bool bfs(int cost){
    queue<int> q;
    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int popped=q.front();
        q.pop();
        
        if(popped==dest) return true;

        for (int i=0; i<board[popped].size();i++){
            int next=board[popped][i].first;
            int nextCost=board[popped][i].second;

            if(!visited[next] && cost<=nextCost){
                visited[next]=true;
                q.push(next);
            }
        }
    }
    return false;

}

int main()
{
    cin >> N>>M;
    for (int k = 0; k < M; k++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        board[a].push_back(make_pair(b,c));
        board[b].push_back(make_pair(a,c));
        max_cost=max(max_cost,c);
    }
    cin>>start>>dest;
    int low=1;
    int high=max_cost;
    while(low<=high){
        int mid =(low+high)/2;
        fill(visited,visited+100001,0);
        bool isOkay=bfs(mid);
        if (isOkay){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<high;
}