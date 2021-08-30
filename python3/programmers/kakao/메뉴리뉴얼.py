from itertools import combinations


def solution(orders, course):
    answer = []
    for x in course:
        hashes = {}
        for item in orders:
            if (len(item) < x):
                continue
            else:
                item2list = list(item)
                temp = list(combinations(item2list, x))
                for q in temp:
                    q = list(q)
                    q.sort()
                    keyname = "".join(q)
                    if (keyname in hashes):
                        hashes[keyname] = hashes[keyname] + 1
                    else:
                        hashes[keyname] = 1
        answerlist = sorted(hashes.items(), key=lambda x: x[1], reverse=True)
        if (len(answerlist) > 0):
            occur = answerlist[0][1]
            if (occur == 1):
                continue
            for x in range(0, len(answerlist)):
                if (occur == answerlist[x][1]):
                    answer.append(answerlist[x][0])
                else:
                    break
    answer.sort()

    return answer