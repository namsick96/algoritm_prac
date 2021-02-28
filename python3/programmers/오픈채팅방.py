def solution(record):
    dic={}
    for k in record:
        msg=k.split()
        if len(msg)==2:
            dic[msg[1]].append([msg[0]])
        else:
            if msg[1] in dic:
                dic[msg[1]].append([msg[0],msg[2]])
            else:
                dic[msg[1]]=[[msg[0],msg[2]]]
    realdic={}
    result=[]
    for k in record:
        msg=k.split()
        if msg[1] not in realdic:
            loglist=dic[msg[1]]
            idx=-1
            while (True):
                if loglist[idx][0]=='Change' or loglist[idx][0]=='Enter':
                    realdic[msg[1]]=loglist[idx][1]
                    break
                else:
                    idx=idx-1
                    continue

        if msg[0]=='Enter':
            result.append(realdic[msg[1]]+"님이 들어왔습니다.")
            continue
        elif msg[0]=='Leave':
            result.append(realdic[msg[1]]+"님이 나갔습니다.")
            continue
        elif msg[0]=='Change':
            continue

    return result