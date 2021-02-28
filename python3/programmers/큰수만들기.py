
def solution(number,k):
    stack=[]
    stack.append(number[0])
    for num in number[1:]:
        while stack and stack[-1]<num and k>0:
            k-=1
            stack.pop()
        stack.append(num)

    if k!=0:
        stack=stack[:-k]

    return "".join(stack)






#오답
#     target=list(number)
# #     biggest=number.index(max(target[:k]))
# #     temp=target[biggest:]
# #     left=k-biggest
# #     delete=[]
# #     for i in range(len(temp)-1):
# #         if temp[i]<temp[i+1]:
# #             delete.append(i)
# #             left-=1
# #         if left==0:
# #             break
# #     final=[]
# #     for j in range(len(temp)):
# #         if j not in delete:
# #             final.append(temp[j])
# #
# #     return "".join(final)
# # print(solution("1924",2))
    오답
    # if biggest>k:
    #     while (biggest>k):
    #         intarget=target[:biggest]
    #         biggest=target.index(max(intarget))
    #
    # if biggest==k:
    #     ans=target[biggest:]
    # if biggest<k:
    #     temp=target[biggest:]
    #     left=k-biggest
    #     idx=0
    #     while left!=0:
    #         if temp[idx]<temp[idx+1]:
    #             del temp[idx]
    #             left-=1
    #         else:
    #             idx+=1
    #     ans=temp
    # return "".join(ans)



#시간초과한 방법
# from itertools import combinations
# def solution(number, k):
#     numlen=len(number)
#     combs=list(combinations(number,numlen-k))
#     combs.sort(reverse=True)
#     return "".join(combs[0])
#
# print(solution("1231234",3))

# a='1924'
# aa=list(a)
#
#print(aa)