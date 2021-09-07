#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#include <string>
#include <vector>

using namespace std;

bool chap(vector<vector<int>> key, vector<vector<int>> lock,int holeCount){
    int M=key.size();
    int N=lock.size();
    
    for(int y=-M+1; y<N; y++){
        for(int x=-M+1; x<N;x++){
            //x,y는 lock에서 key의 시작점
            bool find=true;
            int count=0;
            
            //keyy,keyx 는 key 그리드 내의 위치
            for(int keyy=0; keyy<M; keyy++){
                if(keyy+y>=N or keyy+y<0){
                    continue;
                }
                for(int keyx=0;keyx<M;keyx++){
                    if(keyx+x>=N or keyx+x<0){
                        continue;
                    }
                    if(lock[keyy+y][keyx+x]==key[keyy][keyx]){
                        find=false;
                    }
                    if(lock[keyy+y][keyx+x]==0 && key[keyy][keyx]==1){
                        count++;
                    }
                }
            }
            if(find && count ==holeCount){
                return true;
            }
        }
    }
    return false;
}

vector<vector<int>> rotate90(vector<vector<int>> key){
    int M=key.size();
    vector<vector<int>> answer;
    for (int y=0; y<M;y++){
        vector<int> newRow;
        answer.push_back(newRow);
        for(int x=0; x<M; x++){
            answer[y].push_back(0);
        }
    }
    for (int y=0; y<M;y++){
        for(int x=0; x<M; x++){
            answer[y][x]=key[M-1-x][y];
        }
    }
    return answer;
}
//1,0>> 0,1
//2,1>>1,0
//2,2 >> 2,0

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int N=lock.size();
    int hole=0;
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            if(lock[y][x]==0){
               hole++; 
            }
        }
    }
    
    // 오른쪽 90도 회전 결과물들
    vector<vector<int>> key90=rotate90(key);
    vector<vector<int>> key180=rotate90(key90);
    vector<vector<int>> key270=rotate90(key180);
    
    bool answer = chap(key, lock,hole) || chap(key90,lock,hole) || chap(key180,lock,hole) || chap(key270,lock,hole);
    return answer;
}

int main()
{
    int p;
    cin>>p;
    
    vector<vector<int>> key;
    key[0].push_back(0);
    key[0].push_back(0);
    key[0].push_back(0);
    key[1].push_back(1);
    key[1].push_back(0);
    key[1].push_back(0);
    key[2].push_back(0);
    key[2].push_back(1);
    key[2].push_back(1);

    vector<vector<int>> lock;
    lock[0].push_back(1);
    lock[0].push_back(1);
    lock[0].push_back(1);
    lock[1].push_back(1);
    lock[1].push_back(1);
    lock[1].push_back(0);
    lock[2].push_back(1);
    lock[2].push_back(0);
    lock[2].push_back(1);

    bool answer=solution(key,lock);
    cout<<answer;
}