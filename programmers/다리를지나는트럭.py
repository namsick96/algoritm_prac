def solution(bridge_length, weight, truck_weights):
    over=[]
    onBridge=[]
    onBridgeCount=[]
    count=1
    while (truck_weights or onBridge):


        if len(truck_weights)>0 and sum(onBridge)+truck_weights[0]<=weight:
            cur=truck_weights.pop(0)
            onBridge.append(cur)
            onBridgeCount.append(count)
        if(bridge_length-1==count-onBridgeCount[0]):
            over.append(onBridge.pop(0))
            onBridgeCount.pop(0)
        count+=1
        print(onBridgeCount)
    answer = count
    return answer

print(solution(100,100,[10,10,10,10,10,10,10,10,10,10]))