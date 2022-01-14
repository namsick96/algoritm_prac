#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int bucket[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int k=0; k<n; k++){
        int p;
        cin>>p;
        bucket[p]++;
    }

    

    for(int k=1; k<=10000; k++){
        if(bucket[k]!=0){
            for(int i=0; i<bucket[k]; i++){
                cout<<k<<"\n";
            }
        }
    }

    
}