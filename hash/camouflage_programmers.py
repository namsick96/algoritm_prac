
clothes=[['yellow_hat', 'headgear'], ['blue_sunglasses', 'eyewear'], ['green_turban', 'headgear']]
ans=1
dic={}
for k in clothes:
    if k[1] in dic:
        dic[k[1]]=dic[k[1]]+1
    else:
        dic[k[1]]=1
for q in dic.keys():
    ans=ans*(dic[q]+1)
ans=ans-1
print(ans)

