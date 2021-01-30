from itertools import permutations


def alphabet(get, target):
    nownum = ord(get)
    fornum = ord(target)
    if fornum - nownum <= 13:
        return fornum - nownum
    else:
        return 90 - fornum + 1


def getScore(inlist, length):
    count = 0
    start = 0
    half = length // 2
    for k in inlist:
        if k > start:
            if k - start <= half:
                count += k - start
                start = k
            else:
                count += length - (k - start)
                start = k
        else:
            if start - k <= half:
                count += start - k
                start = k
            else:
                count += length - (start - k)
                start = k
    return count


def dfs_perm(inlist, length):
    score = list(permutations(inlist, len(inlist)))
    minimum = float('inf')
    for k in score:
        ans = getScore(k, length)
        minimum = min(minimum, ans)
    return minimum


def solution(name):
    length = len(name)
    final = ['A' for k in range(length)]
    fixidxlist = []
    for k in range(length):
        if name[k] != final[k]:
            fixidxlist.append(k)
    alphacount = 0
    for k in fixidxlist:
        alphacount += alphabet(final[k], name[k])
    movement = dfs_perm(fixidxlist, length)
    alphacount += movement
    return alphacount