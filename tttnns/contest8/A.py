a, b = [int(x) for x in input().split()]
ans = 0
crash = 0
while a > 0:
    ans += a
    crash += a
    a = 0
    a = crash // b
    crash -= a*b

print(ans)
