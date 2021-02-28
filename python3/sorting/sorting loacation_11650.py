f=open('../test.txt', 'r')

innum=int(f.readline().strip())

whole=[[] for k in range(2000001)]
#whole[0]=-1000000
#whole[1000000]=0
#whole[2000000]=1000000
least=2000000
maximum=0
for k in range(innum):
    a,b=f.readline().strip().split()
    a=int(a)+1000000 #리스트 적재 인덱스로 바꾸자
    if a<least:
        least=a
    if a>maximum:
        maximum=a
    b=int(b)
    whole[a].append(b)

for i in range(least,maximum+1):
    target=whole[i]
    if len(target)==0:
        continue
    elif len(target)==1:
        print(i - 1000000, target[0])
    else:
        target.sort()
        for k in target:
            print(i-1000000, k)


