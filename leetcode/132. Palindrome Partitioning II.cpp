/* 

 
 132. Palindrome Partitioning II
Hard

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:

Input: s = "a"
Output: 0

Example 3:

Input: s = "ab"
Output: 1

 

Constraints:

    1 <= s.length <= 2000
    s consists of lower-case English letters only.
*/

// 自己的计算方法, 用了两轮 dp 算法 56ms

class Solution1
{
public:
    int res = 2000;
    int minCut(string s)
    {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 1; len < n; len++)
        {
            for (int i = 0; i + len < n; i++)
            {
                int j = i + len;
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1] == 1))
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        vector<int> dp2(n, 2000);
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k <= i; k++)
                if (dp[k][i] == 1)
                {
                    if (k == 0)
                    {
                        dp2[i] = 1;
                        break;
                    }
                    else
                        dp2[i] = min(1 + dp2[k - 1], dp2[i]);
                }
        }
        return dp2[n - 1] - 1;
    }
};

// 8ms 算法
class Solution1
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> cut(n + 1, 0); // number of cuts for the first k characters
        for (int i = 0; i <= n; i++)
            cut[i] = i - 1;

        // 循环
        for (int i = 0; i < n; i++)
        {
            // odd length palindrome
            // i 是子字符串的中心点
            // 从单字母开始, 向两边扩张
            // 如果两边的字母相等, 则更新 dp 
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) 
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);

            // even length palindrome
            // i 是偶数长度字符串的中心左点
            // 同理
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) 
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
        }
        return cut[n];
    }
};