#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int H,W;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>H>>W;

    vector<int> v;
    

    for(int i=0; i<W; i++){
        int nowBlock;
        cin>>nowBlock;
        v.push_back(nowBlock);
    }
    int answer=0;
    for(int i=0; i<W; i++){
        int minimum=999;
        int maximumLeft=-1;
        int maximumRight=-1;
        int nowNum=v[i];
        for(int j=0; j<i; j++){
            maximumLeft=max(maximumLeft,v[j]);
        }
        for(int j=i+1; j<W; j++){
            maximumRight=max(maximumRight,v[j]);
        }

        int baseline=min(maximumLeft,maximumRight);
        if(baseline<v[i]){
            continue;
        }
        // cout<<baseline-nowNum<<endl;
        answer+=baseline-nowNum;
    }
    cout<<answer;


    
}