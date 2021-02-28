class Stack():
    def __init__(self):
        self.stacksize=0
        self.emptyreturn=-1
        self.items=[]

    def pop(self):
        if self.stacksize==0:
            print(-1)
            return -1
        else:
            item=self.items[-1]
            del self.items[-1]
            self.stacksize=self.stacksize-1
            print(item)
            return item

    def push(self,innum):
        self.items.append(innum)
        self.stacksize=self.stacksize+1
        return

    def top(self):
        if self.stacksize==0:
            print(-1)
            return -1
        else:
            print(self.items[-1])
            return self.items[-1]

    def empty(self):
        if self.stacksize==0:
            print(1)
            return 1
        else:
            print(0)
            return 0

    def size(self):
        print(self.stacksize)
        return self.stacksize



f=open('../test.txt', 'r')

num=int(f.readline().strip())
stack=Stack()

for k in range(num):
    a=f.readline().strip().split()
    if a[0]=='push':
        stack.push(a[1])
    else:
        s='stack.'+str(a[0])+'()'
        exec(s)

