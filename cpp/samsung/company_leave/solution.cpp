#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int max_num=0;
int T[16];
int P[16];
int N;

void solve(int now_max,int now_idx){

    int new_max=now_max+P[now_idx];
    int next_idx=now_idx+T[now_idx];

    if(next_idx>N+1){
        max_num=max(max_num,now_max);
        return;
    }
    if(next_idx==N+1){
        max_num=max(max_num,new_max);
    }

    else{
        for(int i=next_idx; i<=N; i++){
            solve(new_max,i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;

    for(int i=1; i<N+1; i++){
        cin>>T[i]>>P[i];
    }

    for(int i=1; i<N+1; i++){
        solve(0,i);
    }
    cout<<max_num;
    
}