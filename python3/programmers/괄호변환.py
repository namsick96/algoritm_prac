def isProper(p):
    stack=[]
    count=0
    if p=="":
        return True

    for k in range(len(p)):
        if p[k]=='(':
            stack.append('(')
            count+=1
        else:
            if count==0:
                return False
            if count!=0:
                count-=1
    if count==0:
        return True
    else:
        return False




def solution(p):
    if p=="":
        return ""
    length = len(p)
    countF = 0
    countE = 0
    balanced = []
    rest=[]
    for k in range(length):
        if p[k] == '(':
            countF += 1
        elif p[k] == ')':
            countE += 1
        if (countF == countE) and countF != 0 and countE != 0:
            balanced.append(p[:k+1])
            rest.append(p[k+1:])
    if isProper(balanced[0]):
        return balanced[0]+solution(rest[0])
    else:
        ans='('+solution(rest[0])+')'
        temp=list(balanced[0])
        for k in range(1,len(temp)-1):
            if temp[k]==')':
                ans+='('
            else:
                ans+=')'
        return ans


print(solution("()))((()"))