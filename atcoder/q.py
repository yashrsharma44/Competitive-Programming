
N, R, C = list(map(int, input().split(' ')))
dis = pow(R*R + C*C, 0.5)
cnt = dis // N
if cnt * N < dis:
    cnt += 1
print(int(cnt))
