def solution(n):
    #3진법 >> 0,1,2
    seq=[]
    n=n-1
    while True:
        if n//3==0:
            seq.append(n%3)
            break
        else:
            seq.append(n%3)
            n=n//3
        n-=1
    seq.reverse()
    answer=''
    for k in seq:
        if k==0:
            answer=answer+'1'
        elif k==1:
            answer=answer+'2'
        elif k==2:
            answer=answer+'4'
    return int(answer)
print(solution(12))
"""
012
124
2진법은
01

5
1...2
0...1

6
2...0
0...2

0 is 0
1 is 1
2 is 2
3 is 10
4is 11
5is 12
6 is 20


4>>3
1....0
1>>0
0...0



2 이면 4
1이면 2
0 이면 1

10 >>41
11 >>42
12>>44
13>>111

13>>12
4...0
4>>3
1...0
"""