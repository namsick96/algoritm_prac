def solution(s):
    line=s[1:-1]
    temp=[]
    dic={}
    for k in range(len(line)):
        if line[k]=='{':
            temp.append(k+1)
        elif line[k]=='}':
            temp.append(k)
            numbers=line[temp[0]:temp[1]]
            onepart=list(map(int,numbers.split(',')))
            dic[len(onepart)]=onepart
            temp=[]
    ans=[]
    temp2=[]
    keys=list(dic.keys())
    keys.sort()
    for i in keys:
        for j in dic[i]:
            if j not in ans:
                ans.append(j)
                break

    return ans


solution("{{20,111},{111}}")