f=open('../test.txt','r')

innum=int(f.readline().strip())

wholelist=[[] for k in range(51)]

for k in range(innum):
    line=f.readline().strip()
    linelen=len(line)
    if line not in wholelist[linelen]:
        wholelist[linelen].append(line)
    else:
        continue


for k in wholelist:
    if len(k)==1:
        print(k[0])
    elif len(k)==0:
        continue
    else:
        k.sort()
        for j in k:
            print(j)