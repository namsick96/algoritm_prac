#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int N,L,R;
int board[50][50];
int ally[50][50];
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void dfs(int i, int j, int number){
    if(ally[i][j]==number){
        return;
    }
    ally[i][j]=number;
    for(int k=0; k<4; k++){
        int newi=i+dy[k];
        int newj=j+dx[k];
        if(newi<0 || newi>=N || newj<0 ||newj>=N){
            continue;
        }
    
        int gap=abs(board[i][j]-board[newi][newj]);
        if(gap<=R && gap>=L){
            dfs(newi,newj,number);
        }
    }

}

int findAlly(){
    int number=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(ally[i][j]==0){
                number++;
                
                dfs(i,j,number);
                
            }

        }
    } 
    return number;
}

void move(int num){

    int countArr[2501]={0,};
    int popsumArr[2501]={0,};
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            countArr[ally[i][j]]+=1;
            popsumArr[ally[i][j]]+=board[i][j];
        }
    }

    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int k=ally[i][j];
            int temp=popsumArr[k]/countArr[k];
            board[i][j]=temp;
        }
    }

}



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin>>N>>L>>R;
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    
    int answer=0;
    while(1){
        int num=findAlly();
        //cout<<num<<endl;
        if(num==N*N){
            break;
        }
        
        move(num);
        //init ally
        for(int i=0; i<N; ++i){
            for (int j=0; j<N; ++j){
                ally[i][j]=0;
            }
        } 
        
        answer++;
    }
    cout<<answer;
   
}