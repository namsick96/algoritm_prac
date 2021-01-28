import re

f=open('../test.txt','r')

times=f.readline().strip()
addsub=re.findall('[+-]',times)
b=re.sub('[+-]',' ',times)
integers=list(map(int,b.split()))
stack=[]
minusphrase=False
count=integers[0]
for k in range(len(addsub)):
    if addsub[k]=='-':
        stack.append(integers[k+1])
        minusphrase=True
        continue
    if addsub[k]=='+' and minusphrase:
        stack.append(integers[k+1])
        continue
    else:
        count+=integers[k+1]
minussum=sum(stack)
print(count-minussum)