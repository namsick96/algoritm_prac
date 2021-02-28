def merge(leftlist,rightlist):
    result=[]
    while len(leftlist)>0 or len(rightlist)>0:
        if len(leftlist)>0 and len(rightlist)>0:
            if leftlist[0]<=rightlist[0]:
                result.append(leftlist[0])
                leftlist=leftlist[1:]
            else:
                result.append(rightlist[0])
                rightlist=rightlist[1:]
        elif len(leftlist)>0 and len(rightlist)==0:
            result=result+leftlist
            leftlist=[]
        elif len(leftlist)==0 and len(rightlist)>0:
            result=result+rightlist
            rightlist=[]

    return result

def merge_sort(list1,left,right):
    mid=len(list1)//2
    leftlist=list1[:mid]
    rightlist=list1[mid:]
    if len(list1)<=1:
        return list1

    if (left<right):
        leftlist=merge_sort(leftlist,0,mid-1)
        rightlist=merge_sort(rightlist,0,len(rightlist)-1)
    merged_list=merge(leftlist,rightlist)
    return merged_list



f=open('../test.txt', 'r')

num=int(f.readline().strip())

wholelist=[]
for k in range(num):
    wholelist.append(int(f.readline().strip()))

ans=merge_sort(wholelist,0,len(wholelist)-1)
print(ans)