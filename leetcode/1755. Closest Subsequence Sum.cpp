class Solution
{
public:
    /* 
        和直接进行全部状态遍历  1<<n 个状态

        分成ab两个部分  a+b=n

        1<<a + 1<<b 直接计算量大减

        va 的计算量  1<<a
        得到 va 的全部状态后进行排序

        对vb 的所有状态  1<<b 个状态
        
        lower_bound 二分查找到最相近的值

        后半部分的计算量 (1<<b)*(log 1<<a)

    */

    int minAbsDifference(vector<int> &a, int goal)
    {
        // 直接二分
        int n = a.size(), m = n / 2, r = n - m;
        int ans = 2e9;

        // 分成 va vb 两个 buf  vb 直接使用不需要保存
        vector<int> va;

        // 分别计算全部的状态
        for (int i = 0; i < 1 << m; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < m; ++j)
            {
                if (i >> j & 1)
                    tmp += a[j];
            }
            // 计算 distance 并比较
            ans = min(ans, abs(tmp - goal));

            // 保存到 buf
            va.push_back(tmp);
        }

        // va 升序排序
        sort(va.begin(), va.end());

        // 判断右半边部分
        for (int i = 0; i < 1 << r; ++i)
        {
            int tmp = 0;
            for (int j = 0; j < r; ++j)
            {
                if (i >> j & 1)
                    tmp += a[j + m];
            }
            // 同样的操作
            ans = min(ans, abs(tmp - goal));

            // 当前的 distance
            int k = goal - tmp;

            // 根据distance 找到 va 的部分， 看有没有合适的
            int pos = lower_bound(va.begin(), va.end(), k) - va.begin();

            // 查找离 distance 最近的3个
            for (int j = pos - 1; j <= pos + 1; ++j)
            {
                if (j >= 0 && j < va.size())
                {
                    // 进行比较
                    ans = min(ans, abs(va[j] + tmp - goal));
                }
            }
        }
        return ans;
    }
};

// 别人的代码 但是自己提交会超时
class Solution1
{
public:
    int ans;
    int goal;
    vector<int> nums;
    vector<int> lb, ub;

    int minAbsDifference(vector<int> &nums, int goal)
    {
        // 初始值
        ans = abs(goal);

        // 总数和
        int s = 0;
        for (int i : nums)
            s += i;

        // 总数判断
        ans = min(ans, abs(s - goal));

        // 降序排序
        sort(nums.begin(), nums.end(), greater<int>());

        // 保存值 准备递归
        this->goal = goal;
        this->nums = nums;

        // n 数
        int n = nums.size();

        // 左右 buf 分配空间
        lb.resize(n);
        ub.resize(n);

        // 准备 buf
        // lb 保存最小
        lb[n - 1] = min(0, nums[n - 1]);
        // ub 保存最大
        ub[n - 1] = max(0, nums[n - 1]);

        // 从最小的值开始往前遍历
        for (int i = n - 2; i >= 0; i--)
        {
            // 获得累加最小值
            lb[i] = min(lb[i + 1], lb[i + 1] + nums[i]);
            // 获得累加最大值
            ub[i] = max(ub[i + 1], ub[i + 1] + nums[i]);
        }
        // 深度搜索 i 代表 index
        dfs(0, 0);
        return ans;
    }

    // cur 代表当前 sum
    void dfs(int i, int cur)
    {
        // 计算 distance
        ans = min(ans, abs(cur - goal));

        // ans==0 一定是最小值
        if (ans == 0)
            return;

        // 搜索完成 返回
        if (i >= nums.size())
            return;

        // 因为 lb[i] 是从负数的累加最小值 到 0 的变化 在不断大
        // cur + i  累加最小值 >= goal 中止搜索
        // 当前 lb[i] + cur - goal 只会越来越大
        if (lb[i] + cur >= goal && lb[i] + cur - goal >= ans)
            return;

        // cur + 累加最大值 <= goal 中止搜索
        // ub[i] 同理从正数累加最大值开始到 0 变小
        // ub[i]+cur 只会越来越小   goal - (ub[i] + cur) 会越来越大
        if (ub[i] + cur <= goal && goal - ub[i] - cur >= ans)
            return;

        // 选中 nums[i]
        dfs(i + 1, cur + nums[i]);

        // 不选择 nums[i]
        dfs(i + 1, cur);
    }
};
/* 
1755. Closest Subsequence Sum
Hard

You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

 

Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

Example 2:

Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.

Example 3:

Input: nums = [1,2,3], goal = -7
Output: 7

 

Constraints:

    1 <= nums.length <= 40
    -107 <= nums[i] <= 107
    -109 <= goal <= 109
 */