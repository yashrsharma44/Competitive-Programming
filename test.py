
def main(ratings):
    ratings.append(0)
    stack = [-1]
    N = len(ratings)
    pre = [0] * N
    for i in range(N):
        pre[i] += pre[i-1] + ratings[i-1]
    
    ans = 0
    print(pre)
    for i in range(len(ratings)):
        while ratings[i] < ratings[stack[-1]]:
            h = ratings[stack.pop()]
            w = i - stack[-1] - 1
            ans = max(ans, h * (pre[i] - pre[stack[-1]+1]))
        stack.append(i)
    ratings.pop()
    return ans

import math
from functools import lru_cache
from collections import defaultdict

def main(drivers, batteries, p):
    N, K = len(drivers), len(batteries)
    vis = [False] * K

    cache = {}
    def dp(i, vis, val):
        if i == N:
            return val
        if (i, vis, val) in cache:
            return cache[(i, vis, val)]
        ans = math.inf
        for j in range(K):
            if not vis[j]:
                vis[j] = True
                ans = min(ans, dp(i+1, vis, max(val, abs(drivers[i] - batteries[j]) + abs(batteries[j] - p))))
                vis[j] = False
        cache[(i, vis, val)] = ans
        return ans

    return dp(0, vis, 0)

print(main([3,1],[1,2,3,4],8))            