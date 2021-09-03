from itertools import combinations


def solution(relation):
    columnNum = len(relation[0])
    combs = []
    items = [k for k in range(columnNum)]
    for i in range(1, columnNum + 1):
        temp = list(map(list, combinations(items, i)))
        for k in temp:
            combs.append(k)
    # print(combs)
    candidates = []
    for comb in combs:
        included = False
        for candidate in candidates:
            if (candidate == list(set(candidate) & set(comb))):
                included = True
                break
        if (included):
            continue

        cases = []
        for element in relation:
            temp = []
            for i in comb:
                temp.append(element[i])
            temp = tuple(temp)
            cases.append(temp)
        if (len(cases) == len(list(set(cases)))):
            candidates.append(comb)
    answer = len(candidates)
    return answer