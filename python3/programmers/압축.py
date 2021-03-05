def solution(msg):
    ans=[]
    dictionary = {}
    count=0
    for k in range(65, 91):
        count+=1
        dictionary[chr(k)]=count
    length = len(msg)

    idx=0
    parsenum=0
    while True:
        parsenum+=1
        if (msg[idx:idx+parsenum]in dictionary):
            if idx+parsenum-1==length:
                ans.append(dictionary[msg[idx:idx+parsenum-1]])
                break

        else:
            count+=1
            dictionary[msg[idx:idx+parsenum]]=count
            ans.append(dictionary[msg[idx:idx+parsenum-1]])
            idx=idx+parsenum-1
            parsenum=0
    #ans.append(dictionary[msg[-1]])
    # parsenum=1
    #
    # i=0
    # while (i<length):
    #     if msg[i:parsenum] in dictionary and not(msg[i:i+parsenum+1] in dictionary):
    #         ans.append(dictionary[msg[i:parsenum]])
    #         count+=1
    #         dictionary[msg[i:i+parsenum+1]]=count
    #         parsenum=1
    #         i+=1
    #     elif msg[i:parsenum] in dictionary and (msg[i:i+parsenum+1] in dictionary):
    #         while(1):
    #             parsenum+=1
    #             if not(msg[i:i+parsenum+1] in dictionary):


    return ans



print(solution('KAKAO'))

print(solution('TOBEORNOTTOBEORTOBEORNOT'))