import sys
class Deque():
    def __init__(self,n):
        self.items=[k for k in range(1,n+1)]
        self.idx=0
        self.length=n

    def shuffle(self):
        if self.length==1:
            print(1)
            return False

        last=self.items[-1]
        self.idx+=1
        self.items.append(self.items[self.idx])
        self.idx+=1
        if last==self.items[-1]:
            print(last)
            return False
        return True



f=open('../test.txt', 'r')
num=int(f.readline().strip())

deque=Deque(num)

go=True
while(go):
    go=deque.shuffle()

