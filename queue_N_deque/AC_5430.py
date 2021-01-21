import sys
class Deque():
    def __init__(self,get):
        self.items=get
        if len(self.items)==0:
            self.empty=0
        else:
            self.empty=1
        self.frontidx=0
        #if len(self.item)=0 then it's -1
        self.backidx=len(self.items)-1
        #NOt R >>True, R >>>False
        self.status=True

    def dd(self):
        if self.frontidx-self.backidx>0:
            return 'error'
        if (self.status):
            item=self.items[self.frontidx]
            self.frontidx+=1
            return item
        else:
            item=self.items[self.backidx]
            self.backidx-=1
            return item

    def rr(self):
        self.status=not(self.status)

    def show(self):
        if self.status:
            return self.items[self.frontidx:self.backidx+1]
        else:
            ans=self.items[self.frontidx:self.backidx+1]
            ans.reverse()
        return ans







f=open('../test.txt','r')
num=int(f.readline().strip())

for k in range(num):
    strategy=f.readline().strip()
    length=int(f.readline().strip())
    getList=f.readline().strip()[1:-1].split(',')
    if len(getList)==1 and getList[0]=='':
        getList=[]

    iserror=False
    deque=Deque(getList)
    for foo in strategy:
        if foo=='R':
            deque.rr()
        elif foo=='D':
            item=deque.dd()
            if item=='error':
                iserror=True
                break
            else:
                continue

    ans=deque.show()

    if iserror:
        print('error')
    else:
        print('[',end='')
        print(",".join(map(str,ans))+']')

