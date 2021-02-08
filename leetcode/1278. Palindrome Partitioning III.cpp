/* 
 You are given a string s containing lowercase letters and an integer k. You need to :

    First, change some characters of s to other lowercase English letters.
    Then divide s into k non-empty disjoint substrings such that each substring is palindrome.

Return the minimal number of characters that you need to change to divide the string.

 

Example 1:

Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.

Example 2:

Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.

Example 3:

Input: s = "leetcode", k = 8
Output: 0

 */

// https://leetcode.com/problems/palindrome-partitioning-iii/
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n=s.length();
        if(n==k)return 0;
        
        int ch[101][101]{0};
        
        // dp 求解任意子字符串成为 palindrome 的改变次数
        for(int len=1;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                if(s[i]==s[j]){
                    ch[i][j]=ch[i+1][j-1];
                }
                else{
                    ch[i][j]=ch[i+1][j-1]+1;
                }
            }
        }
        
        // 二维dp 求解最小改变次数
        int dp[101][100]{0};

        // k=1 的边界
        for(int i=0;i<n;i++){
            dp[1][i]=ch[0][i];
        }

        // 子字符串长度等于 k 的边界
        for(int kk=1;kk<=k;kk++){
            dp[k][k-1]=0;
        }
        
        // dp 求解
        for(int kk=2;kk<=k;kk++){
            for(int i=kk;i<n;i++){
                int res=100;
                for(int j=i;j>=kk-1;j--){
                    res=min(res,dp[kk-1][j-1]+ch[j][i]);   
                }
                dp[kk][i]=res;
            }
        }
        
        return dp[k][n-1];
        
    }
};