#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int arr[1000000];
int temp[10000000];

void merge(int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int k=left;

    while(i<=mid && j<=right){
        if(arr[i]>=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }

    if(i>mid){
        for(int l=j; l<=right; l++){
            temp[k++]=arr[l];
        }
    }
    else{
        for(int l=i; l<=mid; l++){
            temp[k++]=arr[l];
        }

    }

    for(int l= left; l<=right; l++){
        arr[l]=temp[l];
    }


}


void merge_sort(int left, int right){

    if(left==right){
        return;
    }
    int mid=(left+right)/2;

    merge_sort(left,mid);
    merge_sort(mid+1,right);
    merge(left,mid,right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int k=0; k<n; k++){
        cin>>arr[k];
    }

    merge_sort(0,n-1);

    for(int k=0; k<n; k++){
        cout<<arr[k]<<"\n";
    }

    
}