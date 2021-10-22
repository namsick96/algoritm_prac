#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <tuple>
#include <string>

using namespace std;

int N;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin>>N;
    string str1="abcsd";
    string ch1="a";
    char ch3='a';
    char ch2=str1[0];//이건 안됨 //str1.substr(0,1); 이게 맞다

    string str2=str1.substr(0,1);

    if(str2==ch1){
        cout<<"damn"<<endl;
    }

    // if(ch1==ch2){
    //     cout<<"hi"<<endl;
    // }

    if(ch2==ch3){
        cout<<"Hi2"<<endl;
    }
   
}