#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
int map[27][27];
bool visited[27][27];

int bfs(int i, int j)
{
    int count = 1;
    queue<pair<int, int> > q;
    pair<int, int> idx = make_pair(i, j);
    visited[i][j] = true;
    q.push(idx);

    while (!q.empty())
    {
        pair<int, int> x = q.front();
        //cout << x.first << " " << x.second << endl;
        q.pop();
        if (map[x.first + 1][x.second] == 1 && visited[x.first + 1][x.second] == false)
        {
            pair<int, int> new_idx = make_pair(x.first + 1, x.second);
            visited[x.first + 1][x.second] = true;
            q.push(new_idx);
            count++;
        }
        if (map[x.first][x.second + 1] == 1 && visited[x.first][x.second + 1] == false)
        {
            pair<int, int> new_idx = make_pair(x.first, x.second + 1);
            visited[x.first][x.second + 1] = true;
            q.push(new_idx);
            count++;
        }
        if (map[x.first - 1][x.second] == 1 && visited[x.first - 1][x.second] == false)
        {
            pair<int, int> new_idx = make_pair(x.first - 1, x.second);
            visited[x.first - 1][x.second] = true;
            q.push(new_idx);
            count++;
        }
        if (map[x.first][x.second - 1] == 1 && visited[x.first][x.second - 1] == false)
        {
            pair<int, int> new_idx = make_pair(x.first, x.second - 1);
            visited[x.first][x.second - 1] = true;
            q.push(new_idx);
            count++;
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;

    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    vector<int> nums;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            //cout << map[i][j] << endl;
            if (map[i][j] == 1 && visited[i][j] == false)
            {
                int num = bfs(i, j);
                nums.push_back(num);
            }
        }
    }
    sort(nums.begin(), nums.end());
    cout << nums.size() << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}