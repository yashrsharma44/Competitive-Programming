res = 0
s = str(input())
# breakpoint()
for init in range(0,100):
    cur = init
    ok = True
    for i in range(0, len(s)):
        res = res + 1
        if s[i] == '+':
            cur = cur + 1
        else:
            cur = cur - 1
        if cur < 0:
            ok = False
            break
    print(init," ",res)
    if ok:
        break
print(res)