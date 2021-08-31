def proper(u):
    ##this logic is for 올바른 괄호 문자열
    stack = []
    idx = 1
    if (u[0] == ")"):
        return False
    stack.append(u[0])
    for i in range(1, len(u)):
        if (u[i] == "("):
            stack.append("(")
        elif (u[i] == ")"):
            stack.pop()
        idx += 1
        if (len(stack) == 0):
            break
    if (idx == len(u)):
        return True
    else:
        return False


def recur(t):
    if (t == ""):
        return ""
    stack = []
    idx = 1
    stack.append(t[0])
    while (len(stack) != 0):
        top = stack[-1]
        if (top != t[idx]):
            stack.pop()
        else:
            stack.append(t[idx])
        idx += 1
    u = t[:idx]
    v = t[idx:]

    good = proper(u)
    if (good):
        temp = recur(v)
        return u + temp
    else:
        temp2 = "("
        temp3 = recur(v)
        temp2 = temp2 + temp3 + ")"
        stripped = u[1:-1]
        for i in stripped:
            if (i == "("):
                temp2 += ")"
            else:
                temp2 += "("
        return temp2


def solution(p):
    answer = recur(p)
    return answer