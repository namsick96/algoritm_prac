#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;



// in
int N;
int M;
int board[500][500];
bool visited[500][500];
int movex[4]={0,1,0,-1};
int movey[4]={1,0,-1,0};
int answer=-1;

void dfs2(vector<pair<int,int> > cases, int idx, int cnt, int price ){
    if(cnt==3){
        answer=max(answer,price);
        return;
    }

    for(int i=idx; i<cases.size(); i++){
        int newprice=price+board[cases[i].first][cases[i].second];
        dfs2(cases,i+1,cnt+1,newprice);
    }
}

void case5(int y, int x){
    int price=board[y][x];
    int casey[4]={y-1,y,y,y+1};
    int casex[4]={x,x-1,x+1,x};
    vector<pair<int, int> > cases;
    for(int i=0; i<4; i++){
        int newy=casey[i];
        int newx=casex[i];
        if(newy<0 || newx<0 || newy>N-1 ||newx>M-1){
            continue;
        }
        cases.push_back(make_pair(newy,newx));
    }
    dfs2(cases,0,0,price);
}

void dfs(int y, int x, int cnt,int price){
    if(cnt==4){
        answer=max(answer,price);
    }
    else{
        for(int i=0; i<4; i++){
            int newy=y+movey[i];
            int newx=x+movex[i];
            if(visited[newy][newx] || newy<0 ||newx<0 ||newy>N-1 ||newx>M-1){
                continue;
            }
            int newprice=price+board[newy][newx];
            int newcnt=cnt+1;
            visited[newy][newx]=true;
            dfs(newy,newx,newcnt,newprice);
            visited[newy][newx]=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin>>board[y][x];
        }
    }

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            visited[y][x]=true;
            dfs(y,x,1,board[y][x]);
            visited[y][x]=false;
            case5(y,x);
        }
    }

    cout<<answer;
    

}