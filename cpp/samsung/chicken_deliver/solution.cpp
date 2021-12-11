#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;


int N,M;
int arr[50][50];
vector<pair<int,int>> chickens;
int minimum=10000000;

void calc(vector<int> &location){
    int profit=0;

    for (int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            if(arr[y][x]==1){
                int mini=10000000;
                for(int i=0; i<location.size(); i++){
                    int p=chickens[location[i]].first;
                    int q=chickens[location[i]].second;
                    mini=min(mini,abs(p-y)+abs(q-x));
                }
                profit+=mini;
            }

        }
    }


    // for(int i=0; i<location.size(); i++){
    
    //     int p=chickens[location[i]].first;
    //     int q=chickens[location[i]].second;
    //     cout<<p<<", "<<q <<endl;
    //     int mini=10000000;
    //     for (int y=0; y<N; y++){
    //         for(int x=0; x<N; x++){
    //             if(arr[y][x]==1){
    //                 mini=min(mini,abs(p-y)+abs(q-x));
    //             }

    //         }
    //     }
    //     profit+=mini;
    // }
    minimum=min(minimum,profit);
    // cout<<endl;
}

void solve(int idx, int cnt, vector<int> &locations){
    if(cnt==M){
        calc(locations);
        return;
    }
    for(int i=idx+1; i<chickens.size(); i++){
        locations.push_back(i);
        solve(i,cnt+1,locations);
        locations.pop_back();
    }



}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                chickens.push_back(make_pair(i,j));
            }
        }
    }
    // cout<<chickens.size()<<endl;

    for(int i=0; i<chickens.size(); i++){

        vector<int> locations;
        locations.push_back(i);
        solve(i,1,locations);
    }
    cout<<minimum;

    
    
}