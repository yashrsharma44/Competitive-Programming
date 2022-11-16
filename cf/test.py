from itertools import permutations

A = "PREJUDICE"

ans = set()

for el in permutations(A):
    l, r, v = -1, -1, -1
    for i in range(len(el)):
        if el[i] == 'E':
            if l == i:
                l = i
            else:
                r = i
        if el[i] == 'J':
            v = i
    if l < v < r:
        ans.add(el)
print(len(ans))
