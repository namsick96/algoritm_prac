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
int K;
int checked[21];

void dfs(int p, int s){
    if (s==K){
        for(int i=0; i<K; i++){
            cout<<checked[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=p; i<N; i++){

        checked[s]=i;
        dfs(i+1,s+1); 

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    dfs(0,0);
    

}