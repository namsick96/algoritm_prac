import copy

def tracking(inlist,num,tracelist):
    if num==0:

        for k in range(len(tracelist)):
            if k!=len(tracelist)-1:
                print(tracelist[k],end=' ')
            else:
                print(tracelist[k])
    else:
        for k in inlist:
            tempnum=num-1
            templist=copy.deepcopy(inlist)
            temptracelist=copy.deepcopy(tracelist)
            temptracelist.append(k)
            templist.remove(k)
            tracking(templist,tempnum,temptracelist)



f=open('../test.txt', 'r')

a,b=map(int,f.readline().strip().split())

setlist=[k for k in range(1,a+1)]

tracking(setlist,b,[])