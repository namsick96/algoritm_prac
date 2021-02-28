def solution(prices):
    answer = []
    for k in range(len(prices)):
        target=prices[k]
        getans=False
        for i in range(k+1,len(prices)):
            if target>prices[i]:
                answer.append(i-k)
                getans=True
                break;
        if not getans:
            answer.append(len(prices)-k-1)



    return answer


print(solution([1, 2, 3, 2, 3]))