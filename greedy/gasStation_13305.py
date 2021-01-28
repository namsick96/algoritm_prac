f=open('../test.txt','r')

city=int(f.readline().strip())
lengths=list(map(int,f.readline().strip().split()))
gas=list(map(int,f.readline().strip().split()))
ans=0
mostmin=min(gas)
mostminidx=gas.index(mostmin)
least=max(gas)
for k in range(len(lengths)):
    if k <mostminidx:
        least=min(least, gas[k])
    else:
        least=mostmin
    ans=ans+least*lengths[k]
print(ans)
#메모리 초과 답변
# count=lengths[0]*gas[0]
#
# minimum=sum(lengths)*sum(gas)*city
#
# stack=[]
# #stack에는 주유한 기름 값이 들어간다.
# for k in range(lengths[0],sum(lengths)+1):
#     stack.append([k])
# while (stack):
#     cur=stack.pop()
#     if sum(cur)==sum(lengths):
#         ans=0
#         for k in range(len(cur)):
#             ans=ans+(cur[k]*gas[k])
#         minimum=min(minimum,ans)
#     else:
#         left=sum(lengths)-sum(cur)
#         nextleft=sum(lengths[:len(cur)+1])-sum(cur)
#         if nextleft<0:
#             for k in range(0,left+1):
#                 stack.append(cur+[k])
#         elif nextleft==left:
#             stack.append(cur+[left])
#         else:
#             for k in range(nextleft,left+1):
#                 stack.append(cur+[k])
#
#
# print(minimum)
#

