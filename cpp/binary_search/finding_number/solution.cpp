#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

void check(int temp1, vector<int> &temp2)
{
    if (temp1 == 10)
    {
        temp2.push_back(temp1);
    }
    if (temp1 == 1)
    {
        temp2.push_back(temp1);
    }
    if (temp1 != 10 and temp1 != 0)
    {
        cout << "Hi\n";
        int temp3 = temp1 + 1;
        int temp4 = temp1 - 1;
        check(temp3, temp2);
        check(temp4, temp2);
    }
}

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
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    /*
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
    }*/

    unsigned char temp1 = 0;
    unsigned char temp2 = 1;
    unsigned char temp3 = 0;
    unsigned char temp4 = 0;
    temp1 = temp1 | temp2 << 7;
    printf("%u\n", temp1);
    temp1 = (temp1 + 1) >> 1;
    temp1 = temp1 | temp2 << 7;
    printf("%u\n", temp1);
    temp3 = temp3 | temp4 << 7;
    printf("%u\n", temp3);
    /*
    vector<int> v2;
    check(5, v2);
    for (int k = 0; k < v2.size(); k++)
    {
        cout << v2[k] << endl;
    }*/
}