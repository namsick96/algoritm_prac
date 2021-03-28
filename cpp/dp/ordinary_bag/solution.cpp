#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int merchan;
    int maxweight;
    cin >> merchan >> maxweight;

    vector<pair<int, int> > v;
    v.push_back(pair<int, int>(0, 0));

    for (int k = 0; k < merchan; k++)
    {
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;
        v.push_back(pair<int, int>(temp1, temp2));
    }

    sort(v.begin(), v.end());

    //storage
    int house[merchan + 1][maxweight + 1];
    for (int i = 0; i < merchan + 1; i++)
    {
        house[i][0] = 0;
    }
    for (int j = 0; j < maxweight + 1; j++)
    {
        house[0][j] = 0;
    }
    for (int i = 1; i < merchan + 1; i++)
    {
        for (int j = 1; j < maxweight + 1; j++)
        {
            if (v[i].first > j)
            {
                house[i][j] = house[i - 1][j];
            }
            else
            {
                if (v[i].second + house[i - 1][j - v[i].first] > house[i - 1][j])
                {
                    house[i][j] = v[i].second + house[i - 1][j - v[i].first];
                }
                else
                {
                    house[i][j] = house[i - 1][j];
                }
            }
            // cout << house[i][j] << endl;
        }
    }
    cout << house[merchan][maxweight];
}