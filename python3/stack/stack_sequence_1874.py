class Stack():
    def __init__(self):
        self.items=[]
        self.count=0

    def push(self,num):
        self.items.append(num)
        self.count+=1
        return

    def pop(self):
        if self.count==0:
            return -1
        else:
            item=self.items[-1]
            del self.items[-1]
            self.count-=1
            return item

    def top(self):
        if self.count==0:
            return -1
        else:
            item=self.items[-1]
            return item

    def size(self):
        return self.count




f=open('../test.txt', 'r')

num=int(f.readline().strip())

first=[k for k in range(1,num+1)]
stack=Stack()
final=[]
actions=[]

for i in range(num):
    innum=int(f.readline().strip())
    final.append(innum)

finalidx=0
firstidx=0
no=False
for j in range(2*num):
    if stack.top()==final[finalidx]:
        stack.pop()
        actions.append('-')
        finalidx+=1
    else:
        if firstidx==len(first):
            print("NO")
            no=True
            break
        else:
            stack.push(first[firstidx])
            actions.append('+')
            firstidx+=1

if not no:
    for i in actions:
        print(i)