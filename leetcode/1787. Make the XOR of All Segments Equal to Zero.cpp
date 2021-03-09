class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {

        int n = nums.size();
        int block = n / k;
        int outer = n % k;

        vector<vector<int>> feq(k, vector<int>(1024, 0));
        vector<set<int>> st(k);

        for (int i = 0; i < nums.size(); i++)
        {
            feq[i % k][nums[i]]++;
            st[i % k].insert(nums[i]);
        }

        vector<vector<int>> dp(k, vector<int>(1024, 2000));

        // 关键在于, 对于某个位置上一次都没出现过的数据, 怎么过滤掉他们
        // 在较为优质的解法中, 可以达成只有有1个位置上的数字全部改变

        // i=0 特殊处理
        int minc = INT_MAX;
        int b1 = 0 < outer ? block + 1 : block;
        for (int j = 0; j < 1024; j++)
        {
            dp[0][j] = b1 - feq[0][j];
            minc = min(minc, dp[0][j]);
        }
        // dp[i][j] 代表前[i]个数字所达成 XOR 为 j 的最小改变量
        for (int i = 1; i < k; i++)
        {
            int b = i < outer ? block + 1 : block;
            //  minc 的意思就是, 对于 st[i]中没出出现的数字, 就是更改量必定为block的数字, 直接用前面的minc+block 作为dp的值
            // 对于没出现过的数字 minc + block 更新dp
            // 可以理解为这一位置的数字是万能，可以变成任何数字然后得到任何XOR结果
            int nminc = INT_MAX;
            for (int j = 0; j < 1024; j++)
            {

                // 这里是错误的， 这里代表了 s[i] 全部变成0
                // dp[i][j]=min(dp[i][j],dp[i-1][j]+b);

                // 这样代表 s[i] 是万能的， 直接用minc来更新
                dp[i][j] = min(dp[i][j], minc + b);

                // 出现过的数字一定会较为优化的更新 dp 值
                for (int num : st[i])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ num] + b - feq[i][num]);
                    // dp[i][j^num]=min(dp[i][j^num],dp[i-1][j]+b-feq[i][num]);
                }
                nminc = min(nminc, dp[i][j]);
            }

            minc = nminc;
        }

        return dp[k - 1][0];
    }
};