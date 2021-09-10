#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 999999999

using namespace std;

struct Node{
    vector<vector<int>> nowBoard;
    int row;
    int col;
    int count;
};

vector<pair<int,int>> casePair(vector<vector<int>> board, int r, int c){
    vector<pair<int,int>> pairs;
    if(board[r][c]!=0){
        for(int y=0; y<4; y++){
            for(int x=0; x<4; x++){
                if(board[r][c]==board[y][x]){
                    pairs.push_back(make_pair(y,x));
                    break;
                }
            }
        }
    }
    else{
        for(int y=0; y<4; y++){
            for(int x=0; x<4; x++){
                if(board[r][c]!=board[y][x]){
                    pairs.push_back(make_pair(y,x));
                }
            }
        }
        
    }
    return pairs;
    
}
int move(vector<vector<int>> board,int nowR,int nowC,int targetRow,int targetCol){
    
    int count=0;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int,pair<int, int> > > q;
    pair<int,pair<int, int>> ele = make_pair(0,make_pair(nowR, nowC));
    q.push(ele);
    
    while(count==0){
        pair<int,pair<int, int>> popped= q.front();
        q.pop();
        
        int nowy=popped.second.first;
        int nowx=popped.second.second;
        //위
        if(nowy!=0){
            nowy-=1;
            while(board[nowy][nowx]==0&&nowy>0){
                nowy-=1;
            }
            if (nowy == targetRow && nowx == targetCol)
            {
                count=popped.first+1;
                break;
            }
            else{
                q.push(make_pair(popped.first+1,make_pair(nowy,nowx)));
            }
        }
        
        nowy=popped.second.first;
        nowx=popped.second.second;
        //아래
        if(nowy!=3){
            nowy+=1;
            while(board[nowy][nowx]==0&&nowy<3){
                nowy+=1;
            }
            if (nowy == targetRow && nowx == targetCol)
            {
                count=popped.first+1;
                break;
            }
            else{
                q.push(make_pair(popped.first+1,make_pair(nowy,nowx)));
            }
        }
        
        nowy=popped.second.first;
        nowx=popped.second.second;
        //오른
        if(nowx!=3){
            nowx+=1;
            while(board[nowy][nowx]==0&&nowx<3){
                nowx+=1;
            }
            if (nowy == targetRow && nowx == targetCol)
            {
                count=popped.first+1;
                break;
            }
            else{
                q.push(make_pair(popped.first+1,make_pair(nowy,nowx)));
            }
        }

        nowy=popped.second.first;
        nowx=popped.second.second;
        //왼
        if(nowx!=0){
            nowx-=1;
            while(board[nowy][nowx]==0&&nowx>0){
                nowx-=1;
            }
            if (nowy == targetRow && nowx == targetCol)
            {
                count=popped.first+1;
                break;
            }
            else{
                q.push(make_pair(popped.first+1,make_pair(nowy,nowx)));
            }
        }
        
        
        
        for (int k = 0; k < 4; k++)
        {
            int newy = popped.second.first + dy[k];
            int newx = popped.second.second + dx[k];

            if (newx >= 0 && newy >= 0 && newx < 4 && newy < 4)
            {
                if (newy == targetRow && newx == targetCol)
                {
                    count=popped.first+1;
                    break;
                }
                else{
                    q.push(make_pair(popped.first+1,make_pair(newy,newx)));
                }
                    
            }
        }
        
    }
    
    return count;
}

Node* solve(Node* node,int targetRow, int targetCol){
    vector<vector<int>> board;
    board.assign(node->nowBoard.size(),vector<int>(node->nowBoard.size()));
    copy(node->nowBoard.begin(),node->nowBoard.end(),board.begin());
    
    int r=node->row;
    int c=node->col;
    int count=node->count;
    
    
    int nowCard=board[r][c];
    
    if(nowCard==0){
        //카드 안지우기
        int tempCount=move(board,r,c,targetRow,targetCol);
        count=count+tempCount;
    }
    else{
        //카드 지우기
        int tempCount=2+move(board,r,c,targetRow,targetCol);
        board[r][c]=0;
        board[targetRow][targetCol]=0;
        count=count+tempCount;
    }
    
    
    
    
    //return
    Node* answerNode=new Node;
    answerNode->nowBoard.assign(board.size(),vector<int>(board.size()));
    copy(board.begin(),board.end(),answerNode->nowBoard.begin());
    answerNode->count=count;
    answerNode->row=targetRow;
    answerNode->col=targetCol;   
    return answerNode;
    
}

int solution(vector<vector<int>> board, int r, int c) {
    vector<int> candidates;
    queue<Node*> q;
    Node* node=new Node;
    node->nowBoard.assign(board.size(),vector<int>(board.size()));
    copy(board.begin(),board.end(),node->nowBoard.begin());
    node->count=0;
    node->row=r;
    node->col=c;
    q.push(node);
    
    while(!q.empty()){
        Node* tempNode=q.front();
        q.pop();
        vector<pair<int,int>> cases = casePair(tempNode->nowBoard,tempNode->row,tempNode->col);
        if(cases.size()==0){
            candidates.push_back(tempNode->count);
            continue;
        }
        for (int k=0; k<cases.size(); k++){
            int targetRow=cases[k].first;
            int targetCol=cases[k].second;
            q.push(solve(tempNode,targetRow,targetCol));
        }
        
    }
    
    
    int answer=INF;
    for(int k=0; k<candidates.size(); k++){
        answer=min(answer,candidates[k]);
    }
    
    return answer;
}