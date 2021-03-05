#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<int> st;
    int iterlen;
    cin >> iterlen;
    // cout << iterlen;

    for (int k = 0; k < iterlen; k++)

    {
        int num;
        cin >> str;
        if (str == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if (str == "top")
        {
            bool emp;
            emp = st.empty();
            if (emp)
            {
                cout << -1 << "\n";
            }
            else
            {
                num = st.top();
                cout << num << "\n";
            }
        }
        else if (str == "size")
        {
            num = st.size();
            cout << num << "\n";
        }
        else if (str == "empty")
        {
            bool emp;
            emp = st.empty();
            if (emp)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (str == "pop")
        {
            bool emp;
            emp = st.empty();
            if (emp)
            {
                cout << -1 << "\n";
            }
            else
            {
                num = st.top();
                st.pop();
                cout << num << "\n";
            }
        }
    }
    return 0;
}
