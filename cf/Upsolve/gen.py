
def func(s):
    return all(s[i] == s[len(s) - i - 1] for i in range(len(s)//2))


print(func(input()))
