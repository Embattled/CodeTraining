/* 
Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​

A string is said to be palindrome if it the same string when reversed.

 

Example 1:

Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.

Example 2:

Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.

 

Constraints:

    3 <= s.length <= 2000
    s​​​​​​ consists only of lowercase English letters.


*/

// https://leetcode.com/problems/palindrome-partitioning-iv/

// 自己的方法  300ms 24MB
class Solution
{
public:
    bool checkPartitioning(string s)
    {

        int n = s.length();
        int dp[2000][2000]{0};
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        // dp 求解任意子字符串是否 palindrome
        for (int len = 1; len < n; len++)
        {
            for (int i = 0; i + len < n; i++)
            {
                int j = i + len;
                if (s[i] == s[j] && (len == 1 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = 1;
                }
            }
        }

        // 二重循环找切点判定
        for (int i = 0; i < n - 2; i++)
        {
            if (dp[0][i])
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (dp[i + 1][j] && dp[j + 1][n - 1])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};



// 6300KB 方法
class Solution2
{
public:
    // 是 palindrome
    bool isPal(string &s, int i, int j)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    bool checkPartitioning(string s)
    {
        // 从第三个字符串开始判断
        for (auto i = 2; i < s.size(); ++i)
        {
            // 尾巴是 palindrome
            if (isPal(s, i, s.size() - 1))
            {
                // 头和中间是 palindrome
                for (auto j = 1; j < i; ++j)
                    if (isPal(s, j, i - 1) && isPal(s, 0, j - 1))
                        return true;
            }
        }
        return false;
    }
};