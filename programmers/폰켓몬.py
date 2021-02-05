def solution(nums):
    outsame=len(set(nums))
    if outsame>len(nums)/2:
        return len(nums)/2
    else:
        return outsame


print(solution([3,3,3,2,2,2]))