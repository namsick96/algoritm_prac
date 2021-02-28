f=open('../test.txt', 'r')

a,b=f.readline().strip().split()
a=int(a)
b=int(b)
base=[]
for k in range(a):
    line=f.readline().strip()
    base.append(line)

idleblack=[]
idlewhite=[]
for k in range(8):
    if k%2==0:
        idleblack.append('BWBWBWBW')
        idlewhite.append('WBWBWBWB')
    else:
        idleblack.append('WBWBWBWB')
        idlewhite.append('BWBWBWBW')


least=8*8
caseleast=0
for i in range(a-7):
    for j in range(b-7):
        idleblackcount=0
        idlewhitecount=0
        for p in range(i,i+8):
            for q in range(j,j+8):
                if idlewhite[p-i][q-j]!=base[p][q]:
                    idlewhitecount+=1
                elif idleblack[p-i][q-j]!=base[p][q]:
                    idleblackcount+=1
        caseleast=min(idleblackcount,idlewhitecount)
        if caseleast<least:
            least=caseleast

print(least)


