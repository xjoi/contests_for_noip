k = int(raw_input())
s = raw_input()
sts = set(s[0])
li = 0
arr = []
for i in range(1, len(s)):
    ch = s[i]
    if ch not in sts:
        sts.add(ch)
        arr.append(s[li:i])
        li = i
arr.append(s[li:])
if len(arr) < k:
    print("NO")
else:
    while len(arr) > k:
        r = arr.pop()
        l = arr.pop()
        arr.append(l + r)
    print("YES")
    for st in arr:
        print(st)
