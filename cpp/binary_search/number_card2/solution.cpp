#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<int> v;

int low_binary_search(int target, int size)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (v[mid] >= target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
int high_binary_search(int target, int size)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (v[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v_size;
    cin >> v_size;
    for (int k = 0; k < v_size; k++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int iternum;
    cin >> iternum;
    for (int k = 0; k < iternum; k++)
    {
        int temp2;
        cin >> temp2;
        int low_ans = low_binary_search(temp2, v_size);
        int high_ans = high_binary_search(temp2, v_size);
        if (high_ans == v_size - 1 && v[v_size - 1] == temp2)
        {
            high_ans++;
        }
        cout << high_ans - low_ans << " ";
    }
}