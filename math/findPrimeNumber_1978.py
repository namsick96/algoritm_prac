def isPrime(n):
    if (n==1):
        return 0
    elif(n==3):
        return 1
    else:
        if (n%2==0):
            if (n==2):
                return 1
            else:
                return 0
        else:
            for k in range(3,n,2):
                if (n%k==0):
                    return 0
            #for loop가 다 끝나서 나머지가 0인게 없는게 검증이 되어야 소수이므로 1을 리턴할 수 있다.
            #이거 깜빡해서 해멨네..
            return 1

f=open('./test.txt','r')
n=int(f.readline().rstrip())
numberlist=list(map(int,f.readline().rstrip().split()))
ans=0
for n in numberlist:
    temp=isPrime(n)

    ans=ans+temp
print(ans)