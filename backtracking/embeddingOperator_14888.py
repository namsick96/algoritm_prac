import copy
def backtrack(num,line,line2):
    global stack
    #add = line2[0]
    #minus = line2[1]
    #multiple = line2[2]
    #div = line2[3]
    if num==1:
        stack.append(line[0])
        return
    else:
        for k in range(4):
            if line2[k]!=0:
                newline1 = copy.deepcopy(line)
                if k==0:
                    newline1[1] = newline1[0] + newline1[1]
                elif k==1:
                    newline1[1] = newline1[0] - newline1[1]
                elif k==2:
                    newline1[1] = newline1[0] * newline1[1]
                elif k==3:
                    if newline1[0]<0 and newline1[1]>0:
                        newline1[1]=-1*((-1*newline1[0])//newline1[1])
                    else:
                        newline1[1] = newline1[0] // newline1[1]
                newline2 = copy.deepcopy(line2)
                newline2[k] -= 1
                backtrack(num - 1, newline1[1:], newline2)






f=open('../test.txt','r')

num=int(f.readline().strip())
line=list(map(int,f.readline().strip().split()))
line2=list(map(int,f.readline().strip().split()))
stack=[]
backtrack(num,line,line2)
print(max(stack))
print(min(stack))
