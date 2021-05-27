#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<int> v;

bool binary_search(int target, int low, int high)
{
    if (low > high)
    {
        return false;
    }
    int mid = (low + high) / 2;
    if (v[mid] == target)
    {
        return true;
    }
    else if (v[mid] > target)
    {
        return binary_search(target, low, mid - 1);
    }
    else
    {
        return binary_search(target, mid + 1, high);
    }
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
        bool ans = binary_search(temp2, 0, v_size - 1);
        if (ans)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}