#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int board[64][64];

void counting(pair<int, int> lefthigh, int length)
{
    if (length == 1)
    {
        if (board[lefthigh.first][lefthigh.second] == 1)
        {
            cout << 1;
            return;
        }
        else
        {
            cout << 0;
            return;
        }
    }
    int starty = lefthigh.first;
    int startx = lefthigh.second;
    int isOne = length * length;
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
    if (squareCount == isOne)
    {
        cout << 1;
        return;
    }
    else if (squareCount == 0)
    {
        cout << 0;
        return;
    }
    else
    {
        cout << "(";
        counting(make_pair(starty, startx), length / 2);
        counting(make_pair(starty, startx + length / 2), length / 2);
        counting(make_pair(starty + length / 2, startx), length / 2);
        counting(make_pair(starty + length / 2, startx + length / 2), length / 2);
        cout << ")";
    }
}

int main()
{
    int num;
    cin >> num;
    for (int y = 0; y < num; y++)
    {
        for (int x = 0; x < num; x++)
        {
            scanf("%1d", &board[y][x]);
        }
    }
    counting(make_pair(0, 0), num);
}