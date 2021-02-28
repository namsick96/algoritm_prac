def change(n, num):
    #n 은 진수
    #num은 타깃 수
    chars='0123456789ABCDEF'
    ans=num//n
    rest=num%n
    item=chars[rest]
    if ans==0:
        return [item]
    else:
        return change(n,ans)+[item]




def solution(n, t, m, p):
    stack=[]
    allnum=t*m
    numbers=[]
    num=0
    while len(numbers)<=t*m+p+1:
        temp=change(n,num)
        numbers+=temp
        num+=1
    count=0
    ans=[]
    for k in range(len(numbers)):
        if k%m==p-1 and count<t:
            ans.append(numbers[k])
            count+=1
    return "".join(ans)

print(solution(16,16,2,2))