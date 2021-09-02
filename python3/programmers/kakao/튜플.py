def solution(s):
    s=s.replace("{","[").replace("}","]")
    arr=eval(s)
    hashes={}
    for ele in arr:
        for num in ele:
            if(num in hashes):
                hashes[num]=hashes[num]+1
            else:
                hashes[num]=1
    ans1=sorted(hashes.items(), key=lambda x: x[1], reverse=True)
    answer=[]
    for k in ans1:
        answer.append(k[0])
    return answer