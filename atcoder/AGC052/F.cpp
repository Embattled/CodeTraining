#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005, M = 998244353;
vector<int> v[N];
int dp[N][2][2], g[2][2], dp2[N][2][2][2], g2[2][2][2], n, x, y;
void dfs(int x, int y)
{
    dp[x][0][0] = dp[x][1][1] = 1;
    for (int i : v[x])
        if (i != y)
        {
            dfs(i, x);
            memset(g, 0, sizeof g);
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    for (int z = 0; z < 2; z++)
                        for (int w = 0; w < 2; w++)
                            g[a][z ^ w ^ (a & b)] = (g[a][z ^ w ^ (a & b)] + dp[x][a][z] * dp[i][b][w]) % M;
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    dp[x][a][b] = g[a][b];
        }
}
void dfs2(int x, int y)
{
    dp2[x][0][0][0] = dp2[x][1][1][0] = 1;
    for (int i : v[x])
        if (i != y)
        {
            dfs2(i, x);
            memset(g2, 0, sizeof g2);
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    for (int z = 0; z < 2; z++)
                        for (int w = 0; w < 2; w++)
                            for (int l = 0; l < 2; l++)
                                g2[a][z ^ l ^ (a & b)][w ^ b] = (g2[a][z ^ l ^ (a & b)][w ^ b] + dp2[x][a][z][w] * dp2[i][b][l][a]) % M;
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    for (int z = 0; z < 2; z++)
                        dp2[x][a][b][z] = g2[a][b][z];
        }
}
int ksm(int x, int y)
{
    int ans = 1;
    for (; y; y >>= 1, x = x * x % M)
        if (y & 1)
            (ans *= x) %= M;
    return ans;
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int Max = 0, flag = 1, l = -1, r = -1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 1)
            continue;
        int cnt = 0;
        for (int j : v[i])
            if (v[j].size() >= 2)
                cnt++;
        Max = max(Max, cnt);
        if (cnt <= 1)
        {
            if (l == -1)
                l = v[i].size() - 1;
            else
                r = v[i].size() - 1;
        }
        else
            flag &= (v[i].size() == 2);
    }
    if (Max == 0)
    {
        printf("%lld\n", (ksm(2, n - 1) + ksm(2, n - 2)) % M);
        return 0;
    }
    if (Max <= 2 && flag)
    {
        int L = n - l - r + 2, all = L * (L + 1) / 2;
        printf("%lld\n", all % M * ksm(2, l + r - 2) % M);
        return 0;
    }
    dfs(1, 0);
    int ans = (dp[1][0][1] + dp[1][1][1]) % M;
    dfs2(1, 0);
    ans -= (dp2[1][0][1][0] + dp2[1][1][1][0]) % M;
    (ans += M) %= M;
    printf("%lld\n", ans);
}
