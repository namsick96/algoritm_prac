#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;



// in
int board[101][101];
int checked[21];
int N;
int K;
int L;
int answer=99999999;
int head=0;
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int y,x;
        cin>>y>>x;
        board[y][x]=1;
    }
    cin>>L;
    queue<pair<int,string> > q;
    for(int i=0; i<L; i++){
        int temp1;
        string temp2;
        cin>>temp1>>temp2;
        pair<int,string> one=make_pair(temp1,temp2);
        q.push(one);
    }
    int timeElapse=0;
    int snakeLength=1;
    pair<int,int> snakeHead=make_pair(1,1);
    deque<pair<int,int> > dq;
    dq.push_back(snakeHead);
    while(true){
        int nextMoveSec;
        string nextMoveDir;
        timeElapse=timeElapse+1;
        //turn around exist;
        if(!q.empty()){
            nextMoveSec=q.front().first;
            nextMoveDir=q.front().second;
            // if(nextMoveSec==timeElapse){
            //     //추가하기 head만 변경
            //     string charL;
            //     if(nextMoveDir=="L"){
            //         if(head==0){
            //             head=3;
            //         }
            //         else{
            //             head=head-1;
            //         }

            //     }
            //     else{
            //         head=(head+1)%4;
            //     }
            //     q.pop();
            //     continue;
            // }
            
            int nextY=snakeHead.first+movey[head];
            int nextX=snakeHead.second+movex[head];
            snakeHead=make_pair(nextY,nextX);

            if(snakeHead.first<1 ||snakeHead.first>N ||snakeHead.second<1 ||snakeHead.second>N){
                cout<<timeElapse;
                return 0;
            }
            for(int k=0; k<dq.size(); k++){
                if(nextY==dq[k].first && nextX==dq[k].second){
                    cout<<timeElapse;
                    return 0;
                }
            }

            if(board[nextY][nextX]==1){
                dq.push_front(snakeHead);
                board[nextY][nextX]=0;
            }
            else{
                dq.push_front(snakeHead);
                dq.pop_back();
            }

            if(nextMoveSec==timeElapse){
                //추가하기 head만 변경
                string charL;
                if(nextMoveDir=="L"){
                    if(head==0){
                        head=3;
                    }
                    else{
                        head=head-1;
                    }

                }
                else{
                    head=(head+1)%4;
                }
                q.pop();
                continue;
            }
        }
        // not next turn
        else{
            int nextY=snakeHead.first+movey[head];
            int nextX=snakeHead.second+movex[head];
            snakeHead=make_pair(nextY,nextX);
            if(snakeHead.first<1 ||snakeHead.first>N ||snakeHead.second<1 ||snakeHead.second>N){
                cout<<timeElapse;
                return 0;
            }
            for(int k=0; k<dq.size(); k++){
                if(nextY==dq[k].first && nextX==dq[k].second){
                    cout<<timeElapse;
                    return 0;
                }
            }

            if(board[nextY][nextX]==1){
                dq.push_front(snakeHead);
                board[nextY][nextX]=0;
            }
            else{
                dq.push_front(snakeHead);
                dq.pop_back();
            }
        }

        // cout<<timeElapse<<" "<<snakeHead.first<<" "<<snakeHead.second<<" "<<dq.size()<<" "<<head<<endl;


    }
    

}