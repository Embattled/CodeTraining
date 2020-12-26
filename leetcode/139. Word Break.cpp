/* 
139. Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

我自己想的是, 从字符串里面找字典里的元素, 然后递归查找从字符串里删除该元素后的结果 , 太多拷贝 , 而且递归耗费空间

该答案的想法
1. 用队列遍历来代替递归
2. 用一个set<int>来记录历史, 一个数字代表该索引之前的子字符串有解, 而且因为是 set 所以不会重复计算
3. 复杂度是 m*n   字符串长度*字典项目数
*/

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();

        queue<int> bfs;

        unordered_set<int> visited;

        bfs.push(0);

        while (!bfs.empty())
        {
            int start = bfs.start;
            bfs.pop();

            if (visited.find(start) == visited.end())
            {
                visited.insert(start);

                for (string word : wordDict)
                {
                    int m = word.length();

                    if (start + m <= n && s.substr(start, m) == word)
                    {
                        if (start + m == n)
                        {
                            return true;
                        }
                        bfs.push(start + m);
                    }
                }
            }
        }
        return false;
    }
};