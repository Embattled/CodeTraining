#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> s(h + 1, vector<char>(w + 1, 0));
    vector<vector<long long>> dp(h + 1, vector<long long>(w + 1, 0));
    dp[1][1] = 1;
    // vector<vector<array<int, 3>>> dp(h + 1, vector<array<int, 3>>(w + 1, array<int, 3>{0}));

    int modulo = 998244353;

    for (int i = 0; i < k; i++)
    {
        int h1, w1;
        char c1;
        cin >> h1 >> w1 >> c1;
        s[h1][w1] = c1;
    }

    // R right
    // D down
    // X both
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int d = i + 1;
            int r = j + 1;

            if (s[i][j] == 0)
            {
                if (d <= h)
                {
                    dp[d][j] += 2 * dp[i][j];
                    dp[d][j] %= modulo;
                }
                if (r <= w)
                {
                    dp[i][r] += 2 * dp[i][j];
                    dp[i][r] %= modulo;
                }
            }
            else
            {
                switch (s[i][j])
                {
                case 'R':
                    if (r <= w)
                    {
                        dp[i][r] += dp[i][j];
                        dp[i][r] %= modulo;
                    }
                    break;
                case 'D':
                    if (d <= h)
                    {
                        dp[d][j] += dp[i][j];
                        dp[d][j] %= modulo;
                    }
                    break;
                default:
                    if (d <= h)
                    {
                        dp[d][j] += dp[i][j];
                        dp[d][j] %= modulo;
                    }
                    if (r <= w)
                    {
                        dp[i][r] += dp[i][j];
                        dp[i][r] %= modulo;
                    }
                    break;
                }
            }
        }
    }
    cout<<dp[h][w]<<endl;

    return 0;
}
