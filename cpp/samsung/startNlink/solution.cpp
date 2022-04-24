#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;



// in
int board[21][21];
int checked[21];
int N;
int answer=99999999;

void dfs(int idx, int selected){
    if(N/2==selected){
        vector<int> teamA;
        vector<int> teamB;
        for(int i=1; i<=N; i++){
            if(checked[i]==0){
                teamB.push_back(i);
            }
            else{
                teamA.push_back(i);
            }
        }
        // vector<pair<int,int> > pairA;
        int sumA=0;
        // vector<pair<int,int> > pairB;
        int sumB=0;
        for(int i=0; i<teamA.size(); i++){
            for(int k=i+1; k<teamA.size(); k++){
                sumA=sumA+board[teamA[i]][teamA[k]]+board[teamA[k]][teamA[i]];
                sumB=sumB+board[teamB[i]][teamB[k]]+board[teamB[k]][teamB[i]];
            }
        }
        if(sumA>sumB){
            int temp=sumA-sumB;
            answer=min(answer,temp);
        }
        else{
            int temp=sumB-sumA;
            answer=min(answer,temp);
        }
    }
    for(int i=idx; i<=N; i++){
        checked[i]=1;
        dfs(i+1,selected+1);
        checked[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for (int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            cin>>board[y][x];
        }
    }

    dfs(1,0);
    cout<<answer;

}