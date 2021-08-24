#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];


int main()
{
    int n,x;
    cin>>n;
    for(int k=0; k<n; k++){
        cin>>arr[k];
    }
    cin>>x;

    sort(arr,arr+n);

    int count=0;
    int start=0;
    int end=n-1;

    while(true){
        if(start>=end){
            break;
        }
        if(arr[start]+arr[end]==x){
            count++;
            start++;
            end--;
        }
        else if (arr[start]+arr[end]>x){
            end--;
        }
        else{
            start++;
        }
    }
    cout<<count<<endl;

    // for(int k=0; k<n; k++){
    //     cout<<arr[k]<<endl;
    // }
    
    
}
