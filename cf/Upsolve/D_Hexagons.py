from collections import defaultdict as ddic
FAST_IO = 0
if FAST_IO:
    import io
    import sys
    import atexit
    rr = iter(sys.stdin.read().splitlines()).next
    sys.stdout = _OUTPUT_BUFFER = io.BytesIO()

    @atexit.register
    def write():
        sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
else:
    rr = raw_input


def rri(): return int(rr())
def rrm(): return map(int, rr().split())
def rrmm(n): return [rrm() for _ in xrange(n)]


####
MOD = 10**9 + 7
YES, NO = "Yes", "No"


def solve(X, Y, A):
    a = b = c = 0
    b -= X
    c += X
    a -= Y
    b += Y
    # print(a, b, c)
    while not (a <= 0 and b >= 0 and c >= 0):
        a, b, c = -b, -c, -a
        A = A[1:] + A[:1]

    print(A, a, b, c)
    # print("A", A)
    cost0, cost1, cost2, cost3, cost4, cost5 = A
    cost0 = min(cost0, cost1 + cost5)
    cost1 = min(cost1, cost0 + cost2)
    right = b
    upright = c
    ans = cost0 * upright + cost1 * right
    return ans


for TC in xrange(rri()):
    X, Y = rrm()
    A = rrm()
    print solve(X, Y, A)
