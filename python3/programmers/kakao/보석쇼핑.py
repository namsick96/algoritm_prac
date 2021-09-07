def solution(gems):
    jewals = set(gems)
    jewal_num = len(jewals)
    gemslen = len(gems)
    first = 0
    second = 0
    line = len(gems)
    candidates = []
    store = {}
    while (True):
        kind = len(store)
        if (first == line):
            break
        if (kind == jewal_num):
            candidates.append([first, second])
            if (store[gems[first]] == 1):
                del store[gems[first]]
            else:
                store[gems[first]] = store[gems[first]] - 1
            first += 1
            continue
        if (second == line):
            break
        if (kind != jewal_num):
            if (gems[second] in store):
                store[gems[second]] += 1
            else:
                store[gems[second]] = 1
            second += 1

    mostgap = line + 1
    answer = [0, 0]
    for can in candidates:
        f = can[0]
        s = can[1]
        if (mostgap > s - f):
            answer = [f + 1, s]
            mostgap = s - f
        else:
            continue
    return answer
