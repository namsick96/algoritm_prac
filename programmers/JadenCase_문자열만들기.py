def solution(s):
    inlist=s.split(' ')
    allword=[]
    for i in range(len(inlist)):
        wordstack=""
        for j in range(len(inlist[i])):
            temp=inlist[i][j]
            num=ord(temp)
            if j==0:
                if num >=97 and num<=122:
                    num=num-32
                    wordstack+=chr(num)
                    continue
                else:
                    wordstack+=inlist[i][j]
            else:
                if num>=65 and num<=90:
                    num=num+32
                    wordstack+=chr(num)
                    continue
                else:
                    wordstack+=inlist[i][j]
        allword.append(wordstack)

    return ' '.join(allword)

ans= solution("3people unFollowed me")
print(ans)