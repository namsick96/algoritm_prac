class Stack():
    def __init__(self):
        self.items=[]

    def pop(self):
        del self.items[-1]
        return

    def push(self,innum):
        self.items.append(innum)
        return

    def stackSum(self):
        print(sum(self.items))
        return

f=open('../test.txt', 'r')

num=int(f.readline().strip())
stack=Stack()
for k in range(num):
    line=int(f.readline().strip())
    if line:
        stack.push(line)
    else:
        stack.pop()

stack.stackSum()