def solution(n):
    changed=bin(n)[2:]
    onecount=changed.count('1')
    while True:
        n+=1
        if bin(n)[2:].count('1')==onecount:
            return n

