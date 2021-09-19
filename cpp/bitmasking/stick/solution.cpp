#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >>X;
    vector<int> bag;
    bag.push_back(64);
    int answer=0;
    while(answer!=X){
        int tempanswer=0;
        for(int k=0; k<bag.size(); k++){
            tempanswer=tempanswer+bag[k];
        }
        if(tempanswer>X){
            int last=bag[bag.size()-1];
            last=last>>1;
            if(tempanswer-last>=X){
                bag[bag.size()-1]=last;
            }
            else{
                bag[bag.size()-1]=last;
                bag.push_back(last);
            }
        }
        answer=tempanswer;
    }

    cout<<bag.size();
    
}