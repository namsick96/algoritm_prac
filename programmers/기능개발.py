import math
def solution(progresses, speeds):
    dic={}
    queue=[]
    for k in range(len(progresses)):
        day=math.floor((100-progresses[k])/speeds[k])
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
    return list(dic.values())