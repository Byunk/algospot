import sys
input = sys.stdin.readline

def wayToBuy():
    cnt = {}
    for i in range(N+1):
        if pSum[i] in cnt:
            cnt[pSum[i]] += 1
        else:
            cnt[pSum[i]] = 1
    
    ret = 0
    for v in cnt.values():
        if v > 1:
            ret = int(ret + ((v * (v-1)) / 2)) % MOD
    return ret % MOD

def maxBuys(n):
    ret = [0 for _ in range(N+1)]
    prev = [-1 for _ in range(K)]
    
    for i in range(N+1):
        # Do not buy ith box
        if i > 0:
            ret[i] = ret[i-1]
        # Buy boxes from prev[pSum[i]] to ith
        if prev[pSum[i]] != -1:
            ret[i] = max(ret[i], ret[prev[pSum[i]]] + 1)
        prev[pSum[i]] = i
    return ret[-1]

MOD = 20091101
T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    if N == 1:
        D = [int(input())]
    else:
        D = list(map(int, input().split()))
        
    pSum = [0]
    for di in D:
        pSum.append((pSum[-1] + di) % K)
    
    ans1 = wayToBuy()
    ans2 = maxBuys(N)
    print(ans1, ans2)
    
