#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

struct info{
    int x;
    int y;
    int friendAround;
    int emptyAround;
};

// int board[21][21];
int maps[21][21];
int neightbor[21][21];
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;

    int prefer[(N*N)+1][4];
    int sequence[N*N];

    for(int i=0; i<N*N; i++){
        int student;
        cin>>student;
        sequence[i]=student;
        for(int k=0; k<4; k++){
            cin>>prefer[student][k];
        }
    }

    // for (int i=1; i<=N; i++){
    //     for(int k=1; k<=N; k++){
    //         if(i==1 || i==N || k==1 ||k==N){
    //             board[i][k]=3;
    //         }
    //         else{
    //             board[i][k]=4;
    //         }
    //     }
    // }
    // board[1][1]=2;
    // board[N][N]=2;
    // board[1][N]=2;
    // board[N][1]=2;

    maps[2][2]=sequence[0];
    // board[1][2]=board[1][2]-1;
    // board[2][1]=board[2][1]-1;
    // board[3][2]=board[3][2]-1;
    // board[2][3]=board[2][3]-1;

    for (int i=1; i<N*N; i++){
        int student=sequence[i];
        vector<info> cases;
        for(int y=1; y<=N; y++){
            for(int x=1; x<=N; x++){
                if(maps[y][x]!=0){
                    continue;
                }
                info newInfo;
                newInfo.x=x;
                newInfo.y=y;
                int friendCnt=0;
                int emptyCnt=0;
                for(int i=0; i<4; i++){
                    int newy=y+movey[i];
                    int newx=x+movex[i];

                    if(newy<1 || newx<1 || newy>N ||newx>N){
                        continue;
                    }

                    if(maps[newy][newx]==0){
                        emptyCnt+=1;
                        continue;
                    }
                    else{
                        for(int k=0; k<4; k++){
                            if(maps[newy][newx]==prefer[student][k]){
                                friendCnt+=1;
                                break;
                            }
                        }
                    }
                }

                newInfo.friendAround=friendCnt;
                newInfo.emptyAround=emptyCnt;
                cases.push_back(newInfo);

            }
        }

        int maxLike=-1;
        vector<info> cases1Pass;
        for(int i=0; i<cases.size(); i++){
            info one=cases[i];
            if(maxLike<one.friendAround){
                cases1Pass.clear();
                cases1Pass.push_back(one);
                maxLike=one.friendAround;
            }
            else if(maxLike==one.friendAround){
                cases1Pass.push_back(one);
            }
            else{
                continue;
            }
        }
        if(cases1Pass.size()==1){
            maps[cases1Pass[0].y][cases1Pass[0].x]=student;
            continue;
        }
        int maxEmpty=-1;
        vector<info> cases2Pass;
        for(int i=0; i<cases1Pass.size(); i++){
            info one= cases1Pass[i];
            if(maxEmpty<one.emptyAround){
                cases2Pass.clear();
                cases2Pass.push_back(one);
                maxEmpty=one.emptyAround;
            }
            else if(maxEmpty==one.emptyAround){
                cases2Pass.push_back(one);
            }
            else{continue;}
        }
        if(cases2Pass.size()==1){
            maps[cases2Pass[0].y][cases2Pass[0].x]=student;
            continue;
        }
        //row
        int maxRow=40;
        vector<info> cases3Pass;
        for(int i=0; i<cases2Pass.size(); i++){
            info one= cases2Pass[i];
            if(maxRow>one.y){
                cases3Pass.clear();
                cases3Pass.push_back(one);
                maxRow=one.y;
            }
            else if(maxRow==one.y){
                cases3Pass.push_back(one);
            }
            else{continue;}
        }
        if(cases3Pass.size()==1){
            maps[cases3Pass[0].y][cases3Pass[0].x]=student;
            continue;
        }

        //row
        int maxCol=40;
        vector<info> cases4Pass;
        for(int i=0; i<cases3Pass.size(); i++){
            info one= cases3Pass[i];
            if(maxCol>one.x){
                cases4Pass.clear();
                cases4Pass.push_back(one);
                maxCol=one.x;
            }
            else if(maxCol==one.x){
                cases3Pass.push_back(one);
            }
            else{continue;}
        }
        if(cases4Pass.size()==1){
            maps[cases4Pass[0].y][cases4Pass[0].x]=student;
            continue;
        }

    }

    // for(int y=0; y<=N+1; y++){
    //     for(int x=0; x<=N+1; x++){
    //         cout<<maps[y][x]<<" ";
    //     }
    //     cout<<endl;
    // }
    int answer=0;
    for(int y=1; y<=N; y++){
        for(int x=1; x<=N; x++){
            int cnt=0;
            int student=maps[y][x];
            for(int i=0; i<4; i++){
                int newy=y+movey[i];
                int newx=x+movex[i];

                if(newy<1 || newx<1 || newy>N ||newx>N){
                    continue;
                }
                for(int k=0; k<4; k++){
                    if(maps[newy][newx]==prefer[student][k]){
                        cnt+=1;
                        break;
                    }
                }
    
            }
            // cout<<y<<" "<<x<<" "<<cnt<<endl;
            if(cnt==1){
                answer+=1;
            }
            else if(cnt==2){
                answer+=10;
            }
            else if(cnt==3){
                answer+=100;
            }
            else if(cnt==4){
                answer+=1000;
            }
        }
    }

    cout<<answer;
}