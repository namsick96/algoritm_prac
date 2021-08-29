def solution(record):
    answer = []
    hashes = {}
    result = []
    for x in record:
        temp = x.split()
        studentID = temp[1]
        cmd = temp[0]
        if (cmd == "Enter"):
            if (studentID not in hashes):
                hashes[studentID] = {'name': temp[2], 'records': [0], 'idx': 0}
                result.append(studentID)
            else:
                hashes[studentID]['name'] = temp[2]
                hashes[studentID]['records'].append(0)  # 0 is enter
                result.append(studentID)
        elif (cmd == "Leave"):
            hashes[studentID]['records'].append(2)  # 2 is leave
            result.append(studentID)
        else:
            # Change
            hashes[studentID]['name'] = temp[2]
    for x in result:
        pointer = hashes[x]['idx']
        if (hashes[x]['records'][pointer] == 0):
            line = hashes[x]['name'] + "님이 들어왔습니다."
            answer.append(line)

        if (hashes[x]['records'][pointer] == 2):
            line = hashes[x]['name'] + "님이 나갔습니다."
            answer.append(line)
        hashes[x]['idx'] = pointer + 1

    return answer