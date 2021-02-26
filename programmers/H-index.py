def solution(citations):
    length=len(citations)
    hindex = 0
    count=0
    for k in range(length+1):
        count=sum(map(lambda x:x>=k,citations)) # k 이상인 값들의 개
        if count>=k:
            hindex=k




    return hindex

print(solution([0,1,1]))