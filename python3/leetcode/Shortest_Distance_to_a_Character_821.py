class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        targetidx = []
        for k in range(len(s)):
            if s[k] == c:
                targetidx.append(k)
        target = 0
        now = 0
        end = len(targetidx)
        ans = []
        while True:
            if now == len(s):
                break
            if target + 1 == end:
                ans.append(abs(now - targetidx[target]))
            else:
                first = abs(now - targetidx[target])
                second = abs(now - targetidx[target + 1])
                if first >= second:
                    target += 1
                    ans.append(second)
                else:
                    ans.append(first)

            now += 1
        return ans




