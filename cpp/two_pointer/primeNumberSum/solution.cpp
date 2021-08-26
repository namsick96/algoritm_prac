#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <cstdlib>
#include <algorithm>
//#define MAX 4000001
using namespace std;

vector<int> arr;

bool prime[4000001];

int main()
{
    int N;
    cin>>N;
    
    prime[1]=true;
    
    for(int i=2; i<sqrt(N+1)+1; i++){
        if(prime[i]){
            continue;
        }
        for(int j=i+i;j<N+1;j+=i){
            prime[j]=true;
        }

    }

    for(int i=2; i<N+1; i++){
        if(!prime[i]){
            arr.push_back(i);
        }
    }


    int start=0;
    int end=0;
    int count=0;

    if(N==1){
        cout<<0;
        return 0;
    }

    long long sumup=0;
    while(true){
        if(sumup==N){
            count++;
            if(end>=arr.size()) break;
            sumup+=arr[end++];
        }
        else if(sumup<N){
            if(end>=arr.size()) break;
            sumup+=arr[end++];
        }
        else{
            sumup-=arr[start];
            start++;
        }
    }

    cout<<count;


       
}
