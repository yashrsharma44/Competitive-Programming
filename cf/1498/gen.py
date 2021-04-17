from functools import lru_cache


@lru_cache(None)
def f(n, k, turn, total):

    if k <= 0:
        return 0
    if n <= 0:
        return 1

    ans = 1
    if turn == 0:
        for i in range(1, n+1):
            ans += f(n-i, k-1, 1-turn, total)
    else:
        for i in range(1, total-n+1):
            ans += f(total - n - i, k-1, 1-turn, total)
    return ans


print(f(500, 250, 0, 500) % (10**9 + 7))
