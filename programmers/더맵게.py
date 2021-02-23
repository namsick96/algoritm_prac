import heapq
def solution(scoville, K):
    heapq.heapify(scoville)
    count=0
    while (scoville):
        first=heapq.heappop(scoville)
        if first>=K:
            return count
        try:
            second=heapq.heappop(scoville)
        except IndexError:
            break
        mixed=first+(2*second)
        heapq.heappush(scoville,mixed)
        count+=1
    return -1

a=[1, 2, 3, 9, 10, 12]
print(solution(a,7))

