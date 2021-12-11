#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;


int N;
int arr[11];
int maximum=-1000000001;
int minimum=1000000001;

void solve(int idx,int plus, int minus, int multiple, int division,int result){
    if (plus==0 && minus==0 && multiple==0 && division==0){
        maximum=max(maximum,result);
        minimum=min(minimum,result);
        return;
    }
    if(plus!=0){
        solve(idx+1,plus-1,minus,multiple,division,result+arr[idx]);
    }
    if(minus!=0){
        solve(idx+1,plus,minus-1,multiple,division,result-arr[idx]);
    }
    if(multiple!=0){
        
        solve(idx+1,plus,minus,multiple-1,division,result*arr[idx]);
    }
    if(division!=0){
        solve(idx+1,plus,minus,multiple,division-1,result/arr[idx]);
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int plus;
    int minus;
    int multiple;
    int division;
    cin>>N;
    for(int i=0; i<N; i++){
        cin >>arr[i];
    }
    cin>>plus>>minus>>multiple>>division;

    solve(1,plus,minus,multiple,division,arr[0]);


    cout<<maximum<<"\n"<<minimum;

    
    
}