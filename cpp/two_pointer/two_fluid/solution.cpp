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
    int N;
    cin>>N;
    for(int k=0; k<N; k++){
        cin>>arr[k];
    }
    sort(arr,arr+N);
    
    int gap=2000000001;
    int first,second;
    int left=0;
    int right=N-1;
    while(true){

        if(left>=right){
            break;
        }
        if(abs(arr[right]+arr[left])<gap){
            gap=abs(arr[right]+arr[left]);
            first=arr[left];
            second=arr[right];
            if(abs(arr[left])<=abs(arr[right])){
                right--;
            }
            else{
                left++;
            }
        }
        else{
            if(abs(arr[left])<=abs(arr[right])){
                right--;
            }
            else{
                left++;
            }
        }
    }
    cout<<first<<" "<<second;

       
}
