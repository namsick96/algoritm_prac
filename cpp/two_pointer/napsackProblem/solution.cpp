#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <math.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long N;
long long C;


long long arr[30];

void dfs(int idx1, int idx2, long long sumup, vector<long long>& v){
    if(idx1==idx2){
        v.push_back(sumup);
        return;
    }
    if(sumup>C){
        return;
    }
    dfs(idx1+1,idx2,sumup,v);
    dfs(idx1+1,idx2,sumup+arr[idx1],v);
}


int main()
{
    cin>>N>>C;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    vector<long long> left;
    vector<long long> right;
    dfs(0,N/2,0,left);
    dfs(N/2,N,0,right);
    // left.push_back(0);
    // right.push_back(0);
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int leftIdx=0;
    int rightIdx=right.size()-1;
    int result=0;
    while(1){
        if(leftIdx==left.size()){
            break;
        }
        if(rightIdx==-1){
            break;
        }
        if(left[leftIdx]+right[rightIdx]<=C){
            result=result+rightIdx+1;
            leftIdx++;
        }
        else{
            rightIdx--;
        }
    }
    cout<<result;
    
       
}
