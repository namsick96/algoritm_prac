f=open('./test.txt','r')

m=int(f.readline().rstrip())
n=int(f.readline().rstrip())
first=True

sum=0
least=0
for k in range(m,n+1):
    if (k==1):
        continue
    elif (k%2==0):
        if (k==2):
            sum=sum+k
            least=k
            first=False
            continue
        else:
            continue
    else:
        divided=False
        for p in range(3,k,2):

            if(k%p==0):
                divided=True
                break
        if (not divided):
            sum=sum+k
            if(first):
                first=False
                least=k


if(sum==0):
    print(-1)
else:
    print(sum)
    print(least)

