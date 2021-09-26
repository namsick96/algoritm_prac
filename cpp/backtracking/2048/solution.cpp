#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;


int answer=0;
int N;


void left(int board[][20]){
    for(int i=0; i<N; i++){
        vector<int> line;
        for(int j=0; j<N; j++){
            line.push_back(board[i][j]);
        }
        int idx1=0;
        int idx2=0;
        vector<int> cons;
        while(idx1<N){
            if(idx2==N){
                if(line[idx1]!=0){
                    cons.push_back(line[idx1]);
                }
                idx1++;
            }

            if(idx1==idx2){
                idx2+=1;
                continue;
            }
            if(line[idx1]==0){
                idx1+=1;
                continue;
            }
            if(line[idx2]==0){
                idx2+=1;
                continue;
            }
            if(line[idx1]==line[idx2]){
                cons.push_back(line[idx1]*2);
                line[idx2]=0;
                idx1+=1;
                idx2+=1;
                continue;
            }
            if(line[idx1]!=line[idx2]){
                cons.push_back(line[idx1]);
                idx1=idx2;
                idx2+=1;
                continue;
            }
        }
        for(int j=0; j<cons.size(); j++){
            board[i][j]=cons[j];
        }
        for(int j=cons.size(); j<N; j++){
            board[i][j]=0;
        }
    }
    
}


void right(int board[][20]){
    for(int i=0; i<N; i++){
        vector<int> line;
        for(int j=N-1; j>=0; j--){
            line.push_back(board[i][j]);
        }
        int idx1=0;
        int idx2=0;
        vector<int> cons;
        while(idx1<N){
            if(idx2==N){
                if(line[idx1]!=0){
                    cons.push_back(line[idx1]);
                }
                idx1++;
            }

            if(idx1==idx2){
                idx2+=1;
                continue;
            }
            if(line[idx1]==0){
                idx1+=1;
                continue;
            }
            if(line[idx2]==0){
                idx2+=1;
                continue;
            }
            if(line[idx1]==line[idx2]){
                cons.push_back(line[idx1]*2);
                line[idx2]=0;
                idx1+=1;
                idx2+=1;
                continue;
            }
            if(line[idx1]!=line[idx2]){
                cons.push_back(line[idx1]);
                idx1=idx2;
                idx2+=1;
                continue;
            }
        }
        for(int j=N-1; j>N-1-cons.size(); j--){
            board[i][j]=cons[N-1-j];
        }
        for(int j=N-1-cons.size(); j>=0; j--){
            board[i][j]=0;
        }
    }
    
}


void up(int board[][20]){
    for(int j=0; j<N; j++){
        vector<int> line;
        for(int i=0; i<N; i++){
            line.push_back(board[i][j]);
        }
        int idx1=0;
        int idx2=0;
        vector<int> cons;
        while(idx1<N){
            if(idx2==N){
                if(line[idx1]!=0){
                    cons.push_back(line[idx1]);
                }
                idx1++;
            }

            if(idx1==idx2){
                idx2+=1;
                continue;
            }
            if(line[idx1]==0){
                idx1+=1;
                continue;
            }
            if(line[idx2]==0){
                idx2+=1;
                continue;
            }
            if(line[idx1]==line[idx2]){
                cons.push_back(line[idx1]*2);
                line[idx2]=0;
                idx1+=1;
                idx2+=1;
                continue;
            }
            if(line[idx1]!=line[idx2]){
                cons.push_back(line[idx1]);
                idx1=idx2;
                idx2+=1;
                continue;
            }
        }
        for(int i=0; i<cons.size(); i++){
            board[i][j]=cons[i];
        }
        for(int i=cons.size(); i<N; i++){
            board[i][j]=0;
        }
    }
    
}


void down(int board[][20]){
    for(int j=0; j<N; j++){
        vector<int> line;
        for(int i=N-1; i>=0; i--){
            line.push_back(board[i][j]);
        }
        int idx1=0;
        int idx2=0;
        vector<int> cons;
        while(idx1<N){
            if(idx2==N){
                if(line[idx1]!=0){
                    cons.push_back(line[idx1]);
                }
                idx1++;
            }

            if(idx1==idx2){
                idx2+=1;
                continue;
            }
            if(line[idx1]==0){
                idx1+=1;
                continue;
            }
            if(line[idx2]==0){
                idx2+=1;
                continue;
            }
            if(line[idx1]==line[idx2]){
                cons.push_back(line[idx1]*2);
                line[idx2]=0;
                idx1+=1;
                idx2+=1;
                continue;
            }
            if(line[idx1]!=line[idx2]){
                cons.push_back(line[idx1]);
                idx1=idx2;
                idx2+=1;
                continue;
            }
        }
        for(int i=N-1; i>N-1-cons.size(); i--){
            board[i][j]=cons[N-1-i];
        }
        for(int i=N-1-cons.size(); i>=0; i--){
            board[i][j]=0;
        }
    }
    
}




void dfs(int b[][20],int cnt){
    if(cnt==5){
        int boardMAX=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                answer=max(answer,b[i][j]);
            }
        }
        return;   
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int leftArr[20][20];
    int rightArr[20][20];
    int upArr[20][20];
    int downArr[20][20];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            leftArr[i][j]=b[i][j];
            rightArr[i][j]=b[i][j];
            upArr[i][j]=b[i][j];
            downArr[i][j]=b[i][j];
        }
    }

    // for(int i=0; i<N; ++i){
    //     for (int j=0; j<N; ++j){
    //         cout<<leftArr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<cnt<<endl;
    //left
    left(leftArr);
    // for(int i=0; i<N; ++i){
    //     for (int j=0; j<N; ++j){
    //         cout<<leftArr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    dfs(leftArr,cnt+1);
    //right
    right(rightArr);
    dfs(rightArr,cnt+1);
    //up
    up(upArr);
    dfs(upArr,cnt+1);
    //down
    down(downArr);
    dfs(downArr,cnt+1);

}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin>>N;
    int board[20][20];
    for(int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            cin >> board[i][j];
        }
    }
    dfs(board,0);
    cout<<answer;
   
}