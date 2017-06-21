n = int(input())
a = [int(x) for x in input().split()]
sm = sum(a)
lst = []
pos = 0
turn = 1
while sm > 0:
    if a[pos] > 0:
        lst.append('P')
        sm -= 1
        a[pos] -= 1
    if pos + turn not in range(len(a)):
        turn = -turn
    pos += turn
    if turn == 1:
        lst.append('R')
    else:
        lst.append('L')
print(''.join(lst[:-1]))
