#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
// int board[300][300];
// bool visited[300][300];

int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dx[8] = {-1, 1, -2, 2, -2, +2, -1, +1};

/*
void reset_board()
{
    //reset board & visited
    memset(board, 0, sizeof(board));
    memset(visited, 0, sizeof(visited));
}
*/

int bfs(int length, pair<int, int> start, pair<int, int> dest)
{
    int board[300][300] = {
        0,
    };
    bool visited[300][300] = {
        0,
    };
    queue<pair<int, int> > q;
    q.push(start);
    int count = 0;
    if (start.first == dest.first && start.second == dest.second)
    {
        return 0;
    }

    while (!q.empty())
    {
        vector<pair<int, int> > waitlist;
        while (!q.empty())
        {
            pair<int, int> popped = q.front();
            q.pop();
            for (int k = 0; k < 8; k++)
            {
                int newx = popped.second + dx[k];
                int newy = popped.first + dy[k];

                if (newx >= 0 && newx < length && newy >= 0 && newy < length)
                {
                    if (visited[newy][newx] == false)
                    {
                        board[newy][newx] = count;
                        visited[newy][newx] = true;
                        waitlist.push_back(make_pair(newy, newx));
                    }
                }
                if (newy == dest.first && newx == dest.second)
                {
                    //reset_board();
                    return board[newy][newx] + 1;
                }
            }
        }

        count++;
        for (int k = 0; k < waitlist.size(); k++)
        {
            q.push(waitlist[k]);
        }
    }
    return 18;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iter;
    cin >> iter;
    for (int k = 0; k < iter; k++)
    {
        int length;
        int s_first;
        int s_second;
        int d_first;
        int d_second;
        cin >> length;
        cin >> s_first >> s_second;
        cin >> d_first >> d_second;
        pair<int, int> start = make_pair(s_first, s_second);
        pair<int, int> dest = make_pair(d_first, d_second);
        int cnt = bfs(length, start, dest);
        cout << cnt << "\n";
    }
}