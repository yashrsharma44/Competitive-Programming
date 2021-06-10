from collections import defaultdict


def main(a):

    total = 0
    o, t, th, f = 0, 0, 0, 0
    N = len(a)
    for i in range(N):
        for j in range(i, N):
            sub = a[i:j+1]

            count = defaultdict(int)
            for el in sub:
                count[el] += 1

            ans = 0
            for k, v in count.items():
                ans += ((v * (v - 1)) // 2)
            if count[1] == 4:
                print("4ers ", sub, ans)
                f += 1
            if(count[1] == 3):
                print("3ers ", sub, ans)
                th += 1
            if(count[1] == 2):
                print("2ers ", sub, ans)
                t += 1
            if(count[1] == 1):
                print("1ers ", sub, ans)
                o += 1
            total += ans
    print(total)
    print(o, t, th, f)


main([1, 1, 2, 3, 1, 1])
