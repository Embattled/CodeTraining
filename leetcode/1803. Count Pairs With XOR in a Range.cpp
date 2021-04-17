// 计算2次无 buffer
// faster than 29.32%,  less than 9.94%
class Solution
{
public:
    int countPairs(vector<int> &A, int low, int high)
    {

        // high+1 - low

        return test(A, high + 1) - test(A, low);
    }

    // 这里是开区间查找
    // test 返回的是  异或 < x 的pair个数
    int test(vector<int> &A, int x)
    {
        // 两个 hash map
        unordered_map<int, int> count, count2;

        // A每一个 元素的 map value = -1
        for (int a : A)
            count[a]--;

        int res = 0;
        // x 是输入的范围

        while (x)
        {

            // k 是 array 的整数值
            // v 是 元素个数
            // 对于 第一个 map 的所有 k-v
            for (auto const &[k, v] : count)
            {
                // 如果 x 最末尾是1, 即 x 是奇数
                // 则如果 pair 的异或等于 x-1, 则满足函数条件 pair 的 xor < x
                // 因此可以直接查找 x-1 ^ key 的个数
                if (x & 1 && count.find((x - 1) ^ k) != count.end())
                    // 当前 v 的个数 * 目标 key的 v 的个数
                    res += v * count[(x - 1) ^ k];

                // 所有的 k 左移一位后的 map值 +=v
                // 舍弃了最后一位, 即除以2, 因此原本该位是 0 或者1 都不用考虑了
                // 存储新的元素个数
                count2[k >> 1] += v;
            }
            // 交换两个 map
            swap(count, count2);
            // 清空 count2 即 count2 是 buffer
            count2.clear();

            // x 右移一位
            x >>= 1;
        }
        // 因为是双向查找, 没有满足 i<j 需要除以二
        return res / 2;
    }
};


// TrieTree 
struct TrieNode
{
    // val 节点值
    int val, cnt = 0;
    TrieNode *son[2]{};
};

// faster than 69.44%
// less than 40.62%

class Solution
{
    vector<int> nums;
    TrieNode *root;

    // dfs 获取 pair 个数
    int dfs(TrieNode *p, int now, int num, int k, int hi)
    {
        // 得到当前 num 的 k 位
        int flag = (num & (1 << k)) ? 1 : 0;
        int ans = 0;

        // 如果第 k 位取 相同的 值
        // 代表 xor 的 k 位取了 0 
        // 即 now 的 k 位置 0 
        if (p->son[flag])
        {
            // (now ^ (1 << k)) - 1
            // 将 now 的第 k 位置 置1 再减 1
            // 代表 k 位右边全都是 1, 然后 k 位是 0 , k 位左边保持不变
            // 如果所有的值都取1仍然小于 hi
            if ((now ^ (1 << k)) - 1 <= hi)
            {
                // 该位的 xor 取0 了以后, 所有的值都小于等于 hi
                // 直接返回节点个数
                ans += p->son[flag]->cnt;
            }

            // 否则需要进一步 deep
            else
            {
                // 进入 flag, 即 xor 取 0 的路线
                // now 的值不用变
                ans += dfs(p->son[flag], now, num, k - 1, hi);
            }
        }

        // 如果 now 的 k 位值取1
        // 此时 k 位的右边都为0
        // 如果 <= hi , 代表还有搞头
        if ((now ^ (1 << k)) <= hi)
        {
            // 进一步判定 
            // 进入 1-flag 路线
            if (p->son[1 - flag])
                
                //  now: xor 的 k 位赋值1
                ans += dfs(p->son[1 - flag], now ^ (1 << k), num, k - 1, hi);
        }
        return ans;
    }

    // 查找小于 hi 的 pair 个数
    int count(int hi)
    {
        int ans = 0;
        // 获取根节点
        TrieNode *p = root;
        // 对每一个 num 进行遍历
        for (int num : nums)
        {
            // now 初始是 0 
            // 代表当前的 xor 的值
            // 从左向右开始搜索
            ans += dfs(p, 0, num, 15, hi);
        }
        return ans;
    }

public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        this->nums = nums;
        root = new TrieNode();

        // 对于每一个 num 
        for (int num : nums)
        {
            // 从root开始遍历
            TrieNode *p = root;

            // Range 15位可以搞定
            // 从左向右
            for (int k = 15; k >= 0; --k)
            {
                // 取得该位的值
                int flag = (num & (1 << k)) ? 1 : 0;
                // 
                if (!p->son[flag])
                {
                    p->son[flag] = new TrieNode();
                }
                // 进入该分支
                p = p->son[flag];
                // 让该分支的值++
                p->cnt++;
            }
        }

        // 返回 xor 小于的 count
        // 这里的查找是 闭区间查找
        return (count(high) - count(low - 1)) / 2;
    }
};

作者：吴自华
链接：https : //leetcode-cn.com/circle/discuss/RAHcuH/view/CSiahv/
              来源：力扣（LeetCode）
                  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。