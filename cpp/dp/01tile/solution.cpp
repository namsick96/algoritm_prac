
#include <iostream>
using namespace std;
long long factorial(int num)
{
    long long result = 1;
    for (int i = 1; i <= num; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    //io check
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;

    long long fibArr[num + 2];
    fibArr[0] = 0;
    fibArr[1] = 1;
    fibArr[2] = 2;
    for (int i = 3; i < num + 2; i++)
    {
        fibArr[i] = (fibArr[i - 1] + fibArr[i - 2]) % 15746;
    }

    long long &result = fibArr[num];
    cout << result;

    return 0;
}
/*
실패의 흔적
우선 팩토리얼로 하면 int 범위 overflow가 난다. 10만 팩토리얼로 하면 당연히 오버플로우 나지..
피보나치 수열의 성질을 띈다. 그거는 체크했는데... 이걸 long을 써야한다는거 몰랐음.
    // long long sum = 0;
    // int onenum = num;
    // int zeronum = 0;

    // while (onenum >= 0)
    // {
    //     long long added = ((factorial(onenum + zeronum)) / (factorial(onenum) * factorial(zeronum)));
    //     sum = sum + added;
    //     onenum -= 2;
    //     zeronum += 1;
    // }
    // int ans = sum % 15746;
    // cout << ans;
    // 1차 :  4!0!/4!0!
    // 2r :   2!1!/2!1!
    // 3r :  0+2!/0!2!

    // 1 - 1 > 1     1 붙이기
    // 2 - 2 > 11 00    1 붙이기
    // 3-  3 > 111 001 100   1 3개 배열 3!/3! 1 1개 00 1개 2!/1!*1!  1+2=3
    // 4-  5 > 0000 0011 1100 1001 1111>>> 1 4개 배열(4!/4!), 1 2개 00 1개 (3!/2!*1!) , 00 2개 배열  2!/2!
    // 1+ 3 + 1
    // 5 - 8개  00001 00100 10000 00111 10011 11001 11100 11111
    // 6 -     000000 000011 001100 110000 001111 110011 100111 11001

    return 0;
}
*/
