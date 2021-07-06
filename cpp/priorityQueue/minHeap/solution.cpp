#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
template <typename T>
class Heap
{
private:
    vector<T> v;
    int heapCount;

public:
    Heap()
    {
        v.push_back(-1);
        heapCount = 0;
    }
    void push(T data)
    {
        v.push_back(data);
        heapCount++;
        int idx = heapCount;
        while (idx > 1 && v[idx] < v[idx / 2])
        {
            T temp = v[idx];
            v[idx] = v[idx / 2];
            v[idx / 2] = temp;
            idx = idx / 2;
        }
    }
    T pop()
    {
        if (v.size() == 1)
        {
            return 0;
        }
        T answer = v[1];
        v[1] = v[heapCount];
        v.pop_back();
        heapCount--;
        int parent = 1;
        while (1)
        {
            int child = parent * 2;
            if (child + 1 <= heapCount && v[child] > v[child + 1])
            {
                child++;
            }
            if (child > heapCount || v[parent] <= v[child])
            {
                break;
            }
            else
            {
                T temp = v[parent];
                v[parent] = v[child];
                v[child] = temp;
                parent = child;
            }
        }
        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Heap<int> heap;
    int arrlen;
    cin >> arrlen;
    for (int k = 0; k < arrlen; k++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            cout << heap.pop() << "\n";
        }
        else
        {
            heap.push(temp);
        }
    }
}