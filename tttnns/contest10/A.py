n = int(input())
st = input()
diff = 0
for ch in st:
    if ch == '1':
        diff += 1
    else:
        diff -= 1
print(abs(diff))
