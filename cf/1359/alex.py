FAST_IO = 0
if FAST_IO:
    import io, sys, atexit
    rr = iter(sys.stdin.read().splitlines()).next
    sys.stdout = _OUTPUT_BUFFER = io.BytesIO()
    @atexit.register
    def write():
        sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
else:
    rr = raw_input
rri = lambda: int(rr())
rrm = lambda: map(int, rr().split())

####
def solve(N, A):
    NINF = float('-inf')
    #dp[m] = max subarray sum ending at A[i] with max m
    dp = [NINF] * 61
    ans = 0
    for x in A:
        ndp = [NINF] * 61
        ndp[x] = max(x, 0)
        bns = NINF
        for m1 in xrange(-30, x):
            bns = max(bns, dp[m1])
        for m1 in xrange(x, 31):
            bns = max(bns, dp[m1])
            ndp[m1] = max(ndp[m1], bns + x)
        dp = ndp
        for i in xrange(-30, 31):
            ans = max(ans, dp[i] - max(0, i))
        #print("!", x, ans)
        print("DP-array")
        print(dp)
    return ans

print solve(rri(), rrm())
