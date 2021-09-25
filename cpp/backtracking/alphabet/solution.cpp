#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

int R,C;
char board[20][20];
int answer;
int alphabet[26]={0,};
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void dfs(int y, int x, int sizes){
    answer=max(answer,sizes);
    for (int i=0; i<4; i++){
        int newy=y+dy[i];
        int newx=x+dx[i];
        // cout<<newx<<endl<<newy<<endl<<C<<endl<<R<<endl;
        
        if(newx>=0 && newx<C && newy>=0 && newy<R){
            if(alphabet[((int)board[newy][newx])-65]==0){
               alphabet[((int)board[newy][newx])-65]=1;
               dfs(newy,newx,sizes+1);
               alphabet[((int)board[newy][newx])-65]=0;
             
            }
            //cout<<sizes<<endl;
        }
    }
    return;

}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin>>R>>C;
    for(int i=0; i<R; ++i){
        for (int j=0; j<C; ++j){
            cin >> board[i][j];
        }
    }

    answer=0;
    alphabet[((int)board[0][0])-65]=1;
    dfs(0,0,1);
    cout<<answer;
   
}