n, m = map(int, input().split())
chains = [[int(x) for x in input().split()][1:] for i in range(m)]
for chain in chains:
    for i in range(len(chain)):
        if chain[i] == i + 1:
            if i != 0: n -= 2
        else:
            break
    n += len(chain) - 1
print(n - 1)
