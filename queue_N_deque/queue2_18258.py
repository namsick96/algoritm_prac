class Queue():
    def __init__(self):
        self.queuesize=0
        self.emptyreturn=-1
        self.items=[]
        self.cnt=0

    def pop(self):
        if self.queuesize==0:
            print(-1)
            return -1
        else:
            item=self.items[self.cnt]
            self.cnt+=1
            self.queuesize=self.queuesize-1
            print(item)
            return item

    def push(self,innum):
        self.items.append(innum)
        self.queuesize=self.queuesize+1
        return

    def back(self):
        if self.queuesize==0:
            print(-1)
            return -1
        else:
            print(self.items[-1])
            return self.items[-1]

    def front(self):
        if self.queuesize==0:
            print(-1)
            return -1
        else:
            print(self.items[self.cnt])
            return self.items[self.cnt]

    def empty(self):
        if self.queuesize==0:
            print(1)
            return 1
        else:
            print(0)
            return 0

    def size(self):
        print(self.queuesize)
        return self.queuesize



f=open('../test.txt','r')

num=int(f.readline().strip())
queue=Queue()

for k in range(num):
    a=f.readline().strip()
    if a[0:3]=='pop':
        queue.pop()
        continue
    elif a[0:4]=='push':
        num=int(a[5:])
        queue.push(num)
        continue
    elif a[0:4]=='size':
        queue.size()
        continue
    elif a[0:4]=='back':
        queue.back()
        continue
    elif a[0:5]=='empty':
        queue.empty()
        continue
    elif a[0:5]=='front':
        queue.front()
        continue

