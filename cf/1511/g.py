import math


def solve():

    for i in range(1, 10):
        for j in range(1, 10):
            for k in range(1, min(i, j) + 1):
                ans1, ans2 = 0, 0

                cc = "1" * k
                if k == 1:
                    ans1 = "1" * (i-1)
                    ans2 = "2" * (j-1)
                    ans1 += "3"
                    ans2 += "4"
                    ans1 = int(ans1)
                    ans2 = int(ans2)
                else:
                    suf = pow(10, k-1)
                    for i in range(1, i - k + 1):

                    

                gcd = math.gcd(ans1, ans2)
                if not (len(str(gcd)) == len(cc)):
                    print(i, j, ans1, ans2, cc, gcd)


solve()
