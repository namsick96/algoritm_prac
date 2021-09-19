#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int arr[51][51];
int visited[51][51];
int number=0;
int m,n;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool check(int number1, int number2){
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(visited[y][x]==number1){
                for(int k=0; k<4; k++){
                    int tempx=x+dx[k];
                    int tempy=y+dy[k];
                    if(tempx<0 || tempx>=n || tempy<0 || tempy>=m){
                        continue;
                    }
                    else{
                        if(visited[tempy][tempx]==number2){
                            return true;
                        }
                    }
                }
            }

        }
    }
    return false;
}

pair<int,int> dfs(int y,int x){

    int count=0;
    stack<pair<int,int>> s;
    s.push(make_pair(y,x));
    number++;
    // visited[y][x]=number;
    // count++;
    while(!s.empty()){
        pair<int,int> popped=s.top();
        s.pop();
        x=popped.second;
        y=popped.first;
        if(visited[popped.first][popped.second]!=0){
            continue;
        }
        visited[popped.first][popped.second]=number;
        count++;
        int dir=arr[popped.first][popped.second];
        //west
        
        // cout<<"new"<<dir<<endl;
        // cout<<((dir&1)==0)<<"\n";
        // cout<<((dir&2)==0)<<"\n";
        // cout<<((dir&4)==0)<<"\n";
        // cout<<((dir&8)==0)<<"\n";
        if((dir&1)==0){
            s.push(make_pair(y,x-1));
        }
        if((dir&2)==0){
            s.push(make_pair(y-1,x));
        }
        if((dir&4)==0){
            s.push(make_pair(y,x+1));
        }
        if((dir&8)==0){
            s.push(make_pair(y+1,x));
        }
    }

    return make_pair(count,number);
    

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            cin>>arr[y][x];
            visited[y][x]=0;
        }
    }
    vector<pair<int,int>> v;

    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(visited[y][x]==0){
                v.push_back(dfs(y,x));
            }
        }
    }
    sort(v.begin(),v.end(),greater<>());
    int answer=0;
    for(int k1=0; k1<v.size()-1; k1++){
        for(int k2=k1+1; k2<v.size(); k2++){
            if(v[k1].first+v[k2].first>answer){
                bool isTrue=check(v[k1].second,v[k2].second);
                if(isTrue){
                    answer=v[k1].first+v[k2].first;
                }
            }
        }
    }

    cout<<v.size()<<"\n"<<v[0].first<<"\n"<<answer<<"\n";
    // for(int y=0; y<m; y++){
    //     for(int x=0; x<n; x++){
    //         cout<<visited[y][x]<<" ";
    //     }
    //     cout<<"\n";
    // }
}