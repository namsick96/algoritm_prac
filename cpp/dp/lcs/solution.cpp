#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1;
    string s2;

    cin >> s1 >> s2;
    int s1len = s1.size();
    int s2len = s2.size();

    int dp[s1len + 1][s2len + 1];
    for (int i = 0; i < s1len + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < s2len + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1])));
        }
    }
    cout << dp[s1.size()][s2.size()];

    // string a;
    // string b;
    // getline(cin, a);
    // getline(cin, b);
    // int firstSize = a.size();
    // int secondSize = b.size();
    // int house[firstSize][secondSize];
    // for (int i=0; i<firstSize; i++){
    //     int idx=0;
    //     for (int j=0; j<secondSize; j++){
    //         if (a[i].compare(b[j])
    //     }
    // }
}