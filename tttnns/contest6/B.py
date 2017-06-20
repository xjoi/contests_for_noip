n, k = [int(x) for x in raw_input().split()]
if (n * n + 1) // 2 < k:
    print("NO")
else:
    print("YES")
    arr = ['L'] * k + ['S'] * ((n * n + 1) // 2 - k)
    s = 'S'.join(arr)
    if n % 2 == 0:
        s += 'S'
    turn = 1
    while s:
        print(s[:n][::turn])
        s = s[n:]
        if n % 2 == 0:
            turn = - turn
