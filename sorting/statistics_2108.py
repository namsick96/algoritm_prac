import math
f=open('../test.txt','r')

num=int(f.readline().strip())

wholelist=[0]*8001
#wholelist[0]=-4000
#wholelist[4000]=0
#wholelist[4001]=1
#wholelist[8000]=4000

sum=0
for k in range(num):
    n=int(f.readline().strip())
    sum=sum+n
    wholelist[4000+n]=wholelist[4000+n]+1


#조건들
first=True
least=0
maximum=0
middlecount=math.ceil(num/2)
middle=0
count=0
freq=[[0,0]]# 0번째가 숫자 1번째가 빈

for k in range(len(wholelist)):
    if wholelist[k]!=0:
        number=wholelist[k]
        #최빈값 체크
        if freq[0][1]<number:
            freq=[[k-4000,number]]
        elif freq[0][1]==number:
            freq.append([k-4000,number])

        #중앙값 찾기 위한 count
        countunder=count+1
        countover=count+number
        if countunder<=middlecount and middlecount<=countover:
            #중앙값
            middle=k-4000
        #중앙값 찾기 위해서 count
        count=countover
        if first:
            least=k-4000
            first=False
        #최대값 찾기 위함.
        maximum=k-4000

#중앙값은 middle
#산술평균
sumans=round(sum/num)
print(sumans)

#중앙값은 middle
print(middle)

#최빈값
if len(freq)>=2:
    freqans=freq[1][0]
else:
    freqans=freq[0][0]
print(freqans)
#범위
rangeans=maximum-least
print(rangeans)