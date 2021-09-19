# def tracking(inlist,num,tracelist):
#     if num==0:
#
#         for k in range(len(tracelist)):
#             if k!=len(tracelist)-1:
#                 print(tracelist[k],end=' ')
#             else:
#                 print(tracelist[k])
#     else:
#         for k in inlist:
#             tempnum=num-1
#             templist=copy.deepcopy(inlist)
#             temptracelist=copy.deepcopy(tracelist)
#             temptracelist.append(k)
#             templist.remove(k)
#             tracking(templist,tempnum,temptracelist)
#
from itertools import combinations
def recur(L,word,idx,mo,ja,lines):
    moeum = ['a', 'e', 'i', 'o', 'u']
    if(len(word)==L):
        if(mo>=1 and ja>=2):
            print(word)
        return
    for i in range(idx,len(lines)-L+len(word)+1):
        if(lines[i] in moeum):
            recur(L,word+lines[i],i+1,mo+1,ja,lines)
        else:
            recur(L,word+lines[i],i+1,mo,ja+1,lines)
    return

def tracking(L,C,line):
    moeum=['a','e','i','o','u']
    lines=sorted(line)
    idx=0
    mo=0
    ja=0
    temp=recur(L,"",idx,mo,ja,lines)



f=open('./test.txt', 'r')

a,b=map(int,f.readline().strip().split())
line=f.readline().strip().split()
tracking(a,b,line)