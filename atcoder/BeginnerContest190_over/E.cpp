#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> pairs(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    int k;
    cin >> k;
    int c[17];
    int cmap[17][17];
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        c[i]--;
    }

    // 计算两点之间的距离
    for (int i = 0; i < k; i++)
    {
        vector<int> now(n, INT_MAX);
        now[c[i]] = 0;
        queue<int> p;
        p.push(c[i]);
        while (!p.empty())
        {
            int nowc = p.front();
            p.pop();

            for (int u : pairs[nowc])
            {
                if (now[u] > now[nowc] + 1)
                {
                    now[u] = now[nowc] + 1;
                    p.push(u);
                }
            }
        }

        for (int j = 0; j < k; j++)
        {
            if (now[c[j]] != INT_MAX)
            {
                cmap[i][j] = now[c[j]];
            }
            else
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // dp
    vector<vector<int>> dp(1<<k,vector<int>(k,INT_MAX));

    // dp的初始状态， 只达成了一个宝石
    for (int i = 0; i < k; i++)
    {
        dp[1<<i][i]=1;
    }

    // 二进制状态遍历
    for (int state = 0; state < 1<<k; state++)
    {
        // 对于每个状态的每个末尾
        for (int tail = 0; tail < k; tail++)
        {
            // 如果该末尾有值，代表是可以出发的状态
            if(dp[state][tail]<INT_MAX){

                // 选择一个新尾巴
                for (int newTail = 0; newTail < k; newTail++)
                {
                    // 新状态
                    int newState=state|1<<newTail;
                    // 新状态的新尾巴的值
                    dp[newState][newTail]=min(dp[newState][newTail],dp[state][tail]+cmap[tail][newTail]);
                }
            }
        }
        
    }
    int ans=INT_MAX;

    for (int i = 0; i < k; i++)
    {
        ans=min(ans,dp[(1<<k)-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}

/* 

 Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 500

points
Problem Statement

There are N
kinds of magical gems, numbered 1,2,…,N, distributed in the AtCoder Kingdom.
Takahashi is trying to make an ornament by arranging gems in a row.
For some pairs of gems, we can put the two gems next to each other; for other pairs, we cannot. We have M pairs for which the two gems can be adjacent: (Gem A1, Gem B1), (Gem A2, Gem B2), …, (Gem AM, Gem BM). For the other pairs, the two gems cannot be adjacent. (Order does not matter in these pairs.)
Determine whether it is possible to form a sequence of gems that has one or more gems of each of the kinds C1,C2,…,CK

. If the answer is yes, find the minimum number of stones needed to form such a sequence.
Constraints

    All values in input are integers.
    1≤N≤105

0≤M≤105
1≤Ai<Bi≤N
If i≠j
, (Ai,Bi)≠(Aj,Bj)
.
1≤K≤17
1≤C1<C2<⋯<CK≤N

Input

Input is given from Standard Input in the following format:

N M
A1 B1
A2 B2
⋮
AM BM
K
C1 C2  ⋯ CK



Output

Print the minimum number of stones needed to form a sequence of gems that has one or more gems of each of the kinds C1,C2,…,CK
.
If such a sequence cannot be formed, print -1 instead.
 */