def solve():
    N = int(input())
    inp = []

    for _ in range(N):
        V, D = input().split(' ')
        inp.append([V, D])

    # try to find the total distance, and check if R distance is > L distance or viceversa
    R, L = 0, 0
    for v, d in inp:
        if d == 'L':
            L += v
        else:
            R += v

    if L < R:
        # remove L
        # remove a subarray which starts with L, and if sum(L) - sum(R) >= 0, remove subarray
        i = 0
        while i < N:
            if inp[i][1] == 'L':
                # start removing subarray
                j = i
                delta = 0
                while j < N and delta >= 0:
                    delta -= inp[j][]


def main():
    T = int(input())

    for _ in range(T):
        solve()
