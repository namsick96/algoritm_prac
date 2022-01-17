#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int arr[1000000];

void quick_sort(int start, int end){
    if(start>=end)return;
    
    int pivot = start;
	int right = end;
	int left = start + 1;
    int temp=arr[pivot];
    arr[pivot]=arr[(left+right)/2];
    arr[(left+right)/2]=temp;

	while (right >= left) { // 엇갈릴때까지 반복
		while (arr[left] < arr[pivot]) left++;
		while (arr[right] > arr[pivot]) right--;
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		else break;
	}
	temp = arr[pivot];
	arr[pivot] = arr[right];
	arr[right] = temp;; // 엇갈렸으니까 바꿈
    


    quick_sort(start,right-1);
    quick_sort(right+1,end);

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

    quick_sort(0,n-1);

    for(int k=0; k<n; k++){
        cout<<arr[k]<<"\n";
    }

    
}