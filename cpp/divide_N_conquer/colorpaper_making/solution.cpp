#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int board[128][128];
int whitecnt = 0;
int bluecnt = 0;

void counting(pair<int, int> lefthigh, int length)
{
    if (length == 1)
    {
        if (board[lefthigh.first][lefthigh.second] == 1)
        {
            bluecnt++;
            return;
        }
        else
        {
            whitecnt++;
            return;
        }
    }
    int starty = lefthigh.first;
    int startx = lefthigh.second;
    int isblue = length * length;
    int squareCount = 0;
    for (int y = starty; y < starty + length; y++)
    {
        for (int x = startx; x < startx + length; x++)
        {
            if (board[y][x] == 1)
            {
                squareCount++;
            }
        }
    }
    if (squareCount == isblue)
    {
        bluecnt++;
        return;
    }
    else if (squareCount == 0)
    {
        whitecnt++;
        return;
    }
    else
    {
        counting(make_pair(starty, startx), length / 2);
        counting(make_pair(starty, startx + length / 2), length / 2);
        counting(make_pair(starty + length / 2, startx), length / 2);
        counting(make_pair(starty + length / 2, startx + length / 2), length / 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    for (int y = 0; y < num; y++)
    {
        for (int x = 0; x < num; x++)
        {
            cin >> board[y][x];
        }
    }

    counting(make_pair(0, 0), num);
    cout << whitecnt << "\n"
         << bluecnt;
}