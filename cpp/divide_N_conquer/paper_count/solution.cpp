#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#define SIZE 2187
using namespace std;
int zeroNum = 0;
int oneNum = 0;
int minusNum = 0;
int board[SIZE][SIZE];

void counting(pair<int, int> idx, int length)
{
    int startX = idx.first;
    int startY = idx.second;
    int flagnum = board[startY][startX];
    if (length == 1)
    {
        if (flagnum == -1)
        {
            minusNum++;
        }
        else if (flagnum == 0)
        {
            zeroNum++;
        }
        else if (flagnum == 1)
        {
            oneNum++;
        }
        return;
    }
    bool allsame = true;
    for (int y = startY; y < startY + length; y++)
    {
        for (int x = startX; x < startX + length; x++)
        {
            if (flagnum != board[y][x])
            {
                allsame = false;
                break;
            }
        }
        if (!allsame)
        {
            break;
        }
    }
    if (allsame)
    {
        if (flagnum == 1)
        {
            oneNum++;
        }
        else if (flagnum == 0)
        {
            zeroNum++;
        }
        else if (flagnum == -1)
        {
            minusNum++;
        }
    }
    else
    {
        counting(make_pair(startX, startY), length / 3);                      //1
        counting(make_pair(startX + (length / 3), startY), length / 3);       //2
        counting(make_pair(startX + (2 * (length / 3)), startY), length / 3); //3

        counting(make_pair(startX, startY + (length / 3)), length / 3);
        counting(make_pair(startX + (length / 3), startY + (length / 3)), length / 3);
        counting(make_pair(startX + (2 * (length / 3)), startY + (length / 3)), length / 3);

        counting(make_pair(startX, startY + (2 * (length / 3))), length / 3);
        counting(make_pair(startX + (length / 3), startY + (2 * (length / 3))), length / 3);
        counting(make_pair(startX + (2 * (length / 3)), startY + (2 * (length / 3))), length / 3);
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
    cout << minusNum << "\n"
         << zeroNum << "\n"
         << oneNum;
}