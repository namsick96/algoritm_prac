import sys

with open("test.txt", "r") as f:
    n = int(f.readline().rstrip())
    list1 = []
    for k in range(n):
        list1.append(f.readline().rstrip())


