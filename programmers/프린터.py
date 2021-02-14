def solution(priorities, location):
    queue=priorities
    idx=0
    count=0
    tf=[False for k in range(len(priorities))]
    tf[location]=True
    queue=list(zip(queue,tf))
    print(queue)
    while True:
        maxim=0
        for k in range(idx,len(queue)):
            maxim=max(queue[k][0],maxim)
        if maxim>queue[idx][0]:

            queue.append(queue[idx])
            idx+=1
        else:
            if queue[idx][1]==True:
                return count+1
            idx+=1
            count+=1


print(solution([1, 1, 9, 1, 1, 1],0))
print(solution([2,1,3,2],2))