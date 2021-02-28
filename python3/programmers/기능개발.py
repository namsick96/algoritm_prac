import math
def solution(progresses, speeds):
    dic={}
    queue=[]
    for k in range(len(progresses)):
        day=math.ceil((100-progresses[k])//speeds[k])
        if k ==0:
            queue.append(day)
        else:
            if queue[-1]>day:
                day=queue[-1]
                queue.append(day)
            else:
                queue.append(day)
        if day in dic.keys():
            dic[day]=dic[day]+1
        else:
            dic[day]=1

    keys=list(dic.keys())
    keys.sort()
    ans=[]
    for q in keys:
        ans.append(dic[q])

    return ans

solution([93, 30, 55],[1, 30, 5])