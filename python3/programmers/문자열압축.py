def solution(s):
    length = len(s)
    ans = []

    if length == 1:
        return 1

    for k in range(1, (length // 2) + 1):
        count = 1
        tempStr = s[:k]
        result = ""
        for i in range(k, length, k):
            if s[i:i + k] == tempStr:
                count += 1
            else:
                if count == 1:
                    count = ""
                result += str(count) + tempStr
                tempStr = s[i:i + k]
                count = 1
        if count == 1:
            count = ""
        result += str(count) + tempStr
        ans.append(len(result))
        result = ""

    return min(ans)