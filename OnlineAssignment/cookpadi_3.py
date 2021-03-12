#! python
import sys

price=[0,180,275,275,232,290,240]

w=int(sys.argv[1])//500

dp=[0]

for now in range(1,w+1):
    m=0
    for cut in range(1,7):
        if now>=cut:
            m=max(m,dp[now-cut]+cut*price[cut])
    dp.append(m)

print(int(dp[w]*5))
