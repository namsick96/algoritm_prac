import math
def solution(s):
    answer=len(s)
    arrlen=len(s)
    for x in range(1,math.ceil((arrlen+1)/2),1):
        start=0
        tempArr=[]
        countArr=[]
        while(start<arrlen):
            if(start==0):
                tempArr.append(s[start:start+x])
                countArr.append(1)
                start=start+x
                continue
            if(tempArr[-1]==s[start:start+x]):
                countArr[-1]=countArr[-1]+1
                start=start+x
            else:
                tempArr.append(s[start:start+x])
                countArr.append(1)
                start=start+x
        temp=0
        for i in range(len(countArr)):
            if(countArr[i]==1):
                temp=temp+len(tempArr[i])
            else:
                numberToString=str(countArr[i])
                temp=temp+len(numberToString)+len(tempArr[i])
        answer=min(answer,temp)
    return answer