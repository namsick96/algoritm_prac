#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>

using namespace std;

int board[9][9];
vector<pair<int,int> > zeroIdx;
int IDX=0;

bool Solve(){
    if(zeroIdx.size()==IDX){ 
        return true;
    }

    int y=zeroIdx[IDX].first;
    int x=zeroIdx[IDX].second;


    int xstart= x/3;
    xstart=xstart*3;
    int ystart=y/3;
    ystart=ystart*3;
    

    int casearr1[10]={false,};
    bool numbers1[10]={false,};
    for(int i=xstart; i<xstart+3; i++){
        for(int j= ystart; j<ystart+3; j++){
            if(board[j][i]!=0){
                numbers1[board[j][i]]=true;
                
            }
        }
    }
    for(int i=1; i<10; i++){
        if(numbers1[i]==false){
            casearr1[i]=true;
        }
    }



    int casearr2[10]={false,};
    bool numbers2[10]={false,};
    for(int k=0; k<9; k++){
        if(board[y][k]!=0){
            numbers2[board[y][k]]=true;
        }
    }
    for(int i=1; i<10; i++){
        if(numbers2[i]==false){
            casearr2[i]=true;
        }
    }


    int casearr3[10]={false,};
    bool numbers3[10]={false,};  
    for(int k=0; k<9; k++){
        if(board[k][x]!=0){
            numbers3[board[k][x]]=true;
        }
    }
    for(int i=1; i<10; i++){
        if(numbers3[i]==false){
            casearr3[i]=true;
        }
    }

    vector<int> casearr4;
    for(int i=1; i<10; i++){
        if(casearr1[i]==true && casearr2[i]==true && casearr3[i]==true) {
            casearr4.push_back(i);
        }
    }


    if(casearr4.size()==0){
        return false;
    }
    for(int i=0; i<casearr4.size(); i++){
        bool tf=false;
        board[y][x]=casearr4[i];
        IDX++;
        tf=Solve();
        if(!tf){
            board[y][x]=0;
            IDX--;
            //zeroIdx.push_front(make_pair(y,x));
        }
        else{
            return true;
        }    
    }
    
    return false;


}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int y=0; y<9; y++){
        for(int x=0; x<9; x++){
            int temp;
            cin>>temp;
            board[y][x]=temp;
            if(temp==0){
                zeroIdx.push_back(make_pair(y,x));
            }
        }
    }
    Solve();

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
   
}