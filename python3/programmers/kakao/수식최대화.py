from itertools import permutations
import copy


def solution(expression):
    operators = []
    for i in expression:
        if (i == "-" or i == "*" or i == "+"):
            operators.append(i)
    expression = expression.replace("-", " ").replace("*", " ").replace("+", " ")
    numbers = expression.split()
    numbers = list(map(int, numbers))

    ops = ["-", "*", "+"]
    cases = list(permutations(ops, len(ops)))
    # print(cases)
    # cases가 연산자 순서 경우 모음 집합

    arr = []
    for i in range(len(operators)):
        arr.append(numbers[i])
        arr.append(operators[i])
    arr.append(numbers[-1])

    maxans = 0
    for case in cases:
        tempArr = copy.deepcopy(arr)
        for op in case:
            while (True):
                try:
                    idx = tempArr.index(op)

                    right = tempArr.pop(idx + 1)
                    calculate = tempArr.pop(idx)
                    left = tempArr.pop(idx - 1)

                    if (calculate == "+"):
                        tempArr.insert(idx - 1, left + right)
                    elif (calculate == "-"):
                        tempArr.insert(idx - 1, left - right)
                    else:
                        tempArr.insert(idx - 1, left * right)
                except:
                    break
        tempResult = abs(int(tempArr[0]))

        maxans = max(maxans, tempResult)

    return maxans