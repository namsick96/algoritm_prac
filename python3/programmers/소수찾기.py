from itertools import permutations

def erastones(num):
    table=[False,False]+[True]*(num-1)

    divided=int(num**(1/2))
    for k in range(2,divided):
        if table[k]==True:
            for j in range(2*k,num+1,k):
                table[j]=False
    return table

def solution(numbers):
    length=len(numbers)
    all=[]
    for k in range(length):
        all.append(numbers[k])
    ans=[]
    for i in range(1,length+1):
        temp=list(permutations(all,i))
        for q in range(len(temp)):
            if temp[q][0]=='0':
                continue
            number=""
            for j in range(len(temp[q])):
                number+=temp[q][j]
            ans.append(number)
    final=set(map(int,ans))
    maxfinal=max(final)
    minors=erastones(maxfinal)
    count=0
    for t in final:
        if minors[t]==True:
            count+=1
        else:
            pass
    return count

print(solution("011"))