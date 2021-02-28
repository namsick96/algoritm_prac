def stars(n):
    global Map
    if n==3:
        Map[0][:3]=[1]*3
        Map[1][:3]=[1,0,1]
        Map[2][:3]=[1]*3
        return
    else:
        a=n//3
        stars(a)
        for i in range(3):
            for j in range(3):
                if i==1 and j==1:
                    continue
                else:
                    for k in range(a):
                        Map[a*i+k][a*j:a*(j+1)]=Map[k][:a]


n=27
Map=[[0 for k in range(n)] for p in range(n)]
stars(n)
for k in Map:
    for j in k:
        if j:
            print('*',end='')
        else:
            print(' ',end='')
    print()








#f=open('./test.txt','r')

#n=int(f.readline().strip())

