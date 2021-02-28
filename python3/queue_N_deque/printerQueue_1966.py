import sys

class Node():
    def __init__(self,name,priority):
        self.name=name
        self.priority=priority

    def getName(self):
        return self.name

    def getPriority(self):
        return self.priority

class Queue():
    def __init__(self):
        self.items=[]
        self.length=len(self.items)
        self.idx=0

    def dequeue(self):
        if self.idx==self.length:
            return -1
        item=self.items[self.idx]
        self.idx+=1
        return item

    def enqueue(self,innum):
        self.items.append(innum)
        self.length+=1

    def front(self):
        if self.idx==self.length:
            return -1
        item=self.items[self.idx]
        return item

f=open('../test.txt', 'r')

num=int(f.readline().strip())

for k in range(num):
    a,b=map(int,f.readline().strip().split())
    prio=f.readline().strip().split()
    queue=Queue()
    #queue set
    for p in range(a):
        if p==b:
            node=Node('target',prio[p])
            queue.enqueue(node)
        else:
            node=Node('else',prio[p])
            queue.enqueue(node)
    prioidx=0
    prio.sort(reverse=True)
    count=0
    while(True):
        if queue.front()==-1:
            print('no')
            break
        elif queue.front().getPriority()<prio[prioidx]:
            item=queue.dequeue()
            queue.enqueue(item)
        else:
            count+=1
            item=queue.dequeue()
            prioidx+=1
            if item.getName()=='target':
                print(count)
                break
            else:
                pass



