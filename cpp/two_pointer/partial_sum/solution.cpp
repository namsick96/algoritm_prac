#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];

int main()
{
    int N,S;
    cin>>N>>S;
    for(int k=0; k<N; k++){
        cin>>arr[k];
    }

    int start=0;
    int end=1;
    int tempsum=arr[0];
    int length=MAX;
    while(1){
        if(end==N+1){
            break;
        }
        if(length==1){
            break;
        }
        if(tempsum>=S){
            length=min(end-start,length);
            tempsum=tempsum-arr[start];
            start++;
        }
        else{
            tempsum=tempsum+arr[end];
            end++;
        }
    }




    if(length==MAX){
        cout<<0;
    }
    else{
        cout<<length;
    }


       
}
