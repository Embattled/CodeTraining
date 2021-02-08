/* 
Given a string s, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:

Input: s = "abcd"
Output: "dcbabcd"

 

Constraints:

    0 <= s.length <= 5 * 10^4
    s consists of lowercase English letters only.

*/

// 字符串超级长
// 使用KMP算法进行快速匹配

class Solution
{
public:
    string shortestPalindrome(string s)
    {

        // Find longset palindrome
        int n = s.length();
        if (n == 1)
            return s;

        string sr = s;
        reverse(sr.begin(), sr.end());

        vector<int> next(n + 1, 0);
        int i = 1, j = 0;


        // KMP算法计算 Next 数列
        while (i < n)
        {
            // 如果某个位置字符串相同
            if (s[i] == s[j])
            {

                // 在下个字符时
                i++;
                j++;

                // 如果该 s[i]匹配失败
                // 可以直接返回到 s[j] 进行匹配
                if (s[i] != s[j])
                {
                    next[i] = j;
                    j = next[j];
                }
                // 但如果这里 s[i] 还是等于 s[j] 则没必要返回到 s[j], 直接双重返回
                // 直接就能够返回到 s[i] 绝对不等于 s[next[i]] 的位置
                else
                {
                    next[i] = next[j];
                }
            }
            // 如果 s[i] != s[j] 
            else
            {
                // 如果 j 已经到最开始了
                // next[i]=0 是默认值不用管
                // 直接 i++ 判定下一个字符
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    // 返回上一个 next[j]
                    j = next[j];
                }
            }
        }


        // 使用KMP进行快速匹配
        i = 0;
        j = 0;

        // 匹配到 sr 结束时
        while (i < n)
        {
            if (sr[i] == s[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    j = next[j];
                }
            }
        }

        // 使用记录到的 j 来拼接成最后的结果
        return sr + s.substr(j);
    }
};