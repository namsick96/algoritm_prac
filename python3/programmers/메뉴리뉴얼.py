from itertools import combinations


def solution(orders, course):
    ans=[]
    for k in course:
        dic={}
        for i in orders:
            temp = list(i)
            combs = list(combinations(temp, k))
            for j in combs:
                listedj=list(j)
                listedj.sort()
                keyname="".join(listedj)
                if keyname in dic:
                    dic[keyname] += 1
                else:
                    dic[keyname] = 1
        maxvals=[[k,v] for k, v in dic.items() if max(dic.values()) == v]
        for q in maxvals:
            if q[1]>=2:
                ans.append(q[0])
    ans.sort()
    return ans

solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],[2,3,5])