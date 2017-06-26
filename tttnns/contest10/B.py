import sys
n = int(input())
a = [int(x) for x in input().split()]
for i in range(1000):
    turn = n - a[0]
    ok = True
    for i in range(len(a)):
        a[i] = (a[i] + (turn if i % 2 == 0 else -turn)) % n
        if a[i] != i:
            ok = False
    if ok:
        print("Yes")
        sys.exit(0)
print("No")
