import sys
class CircularQueue():
    def __init__(self,num):
        self.items=[k for k in range(1,num+1)]
        self.length=num
        self.idx=0

    def poptarget(self,k):
        if self.length==0:
            return -1
        targetidx=(self.idx+k-1)%self.length
        item=self.items[targetidx]
        del self.items[targetidx]
        self.length-=1
        self.idx=targetidx
        return item




f=open('../test.txt','r')
a,b=map(int,f.readline().strip().split())
queue=CircularQueue(a)
ans=[]
while (True):
    get=queue.poptarget(b)
    if get==-1:
        break
    else:
        ans.append(get)
print("<",end="")
print(", ".join(map(str,ans)),end=">")
