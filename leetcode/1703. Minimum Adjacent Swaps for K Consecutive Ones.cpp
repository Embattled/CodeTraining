/* 
You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.

Return the minimum number of moves required so that nums has k consecutive 1's.

 

Example 1:

Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.

Example 2:

Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].

Example 3:

Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.

 

Constraints:

    1 <= nums.length <= 105
    nums[i] is 0 or 1.
    1 <= k <= sum(nums)
*/

/* 
    要点总结:
    1. 移动1的时候, 只需要计算到目的地经过了多少个0
    2. 以某一个1为中心的时候, 只需要计算其他的1到该1中间的0 的个数  
*/

class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {

        // in order to move a 1 towards another position
        // the amount of moves required is just the number of 0's that you pass.

        int n = nums.size();

        vector<int> oneIndex;
        vector<int> zeroIndex;
        vector<int> zeroespref(nums.size(), 0);
        int zerosum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                oneIndex.push_back(i);
            }
            else
            {
                zerosum++;
                zeroIndex.push_back(i);
            }
            zeroespref[i] = zerosum;
        }

        int minres = INT_MAX;
        int onesum = oneIndex.size();

        int saveDist = 0;

        for (int i = 0; i < k; i++)
        {
            saveDist += zeroespref[oneIndex[i]] - zeroespref[oneIndex[0]];
        }
        minres = min(minres, saveDist);

        // centered at i
        int left = 0;
        int right = k - 1;

        for (int i = 1; i < onesum; i++)
        {
            int change = zeroespref[oneIndex[i]] - zeroespref[oneIndex[i - 1]];

            saveDist += (2 * i - left - right - 1) * change;

            while (right + 1 < onesum)
            {
                int changeLeft = zeroespref[oneIndex[i]] - zeroespref[oneIndex[left]];
                int changeRight = zeroespref[oneIndex[right + 1]] - zeroespref[oneIndex[i]];

                if (changeRight < changeLeft)
                {
                    saveDist += changeRight - changeLeft;
                    right++;
                    left++;
                }
                else
                    break;
            }

            minres = min(minres, saveDist);

            if (right == i && right + 1 < onesum)
            {
                int changeLeft = zeroespref[oneIndex[i]] - zeroespref[oneIndex[left]];
                int changeRight = zeroespref[oneIndex[right + 1]] - zeroespref[oneIndex[i]];

                saveDist += changeRight - changeLeft;
                right++;
                left++;
            }
        }
        return minres;
    }
};

// Best Speed
// 只考虑了以区间最中心的1 为聚合中心， 为什么能得出正确结果？
// 假设存在某个区间，以最中心聚合不能得到最优解, 即最优聚合点在区间偏左或者偏右的位置
// 那么设最中心聚合的位移量是 dist , 假设最优聚合点在左侧偏移一个点  到中心点的位移量为 x
// 应该有   总位移改变量  < 0 
// 即      ((右侧点的个数+1)*x )-(左侧的点的个数*x)  < 0
// 因为  right +1 >= left  因此 总位移量 < 0 不成立
// 同理, 假设最优聚合点在右侧偏移一个点
// 即  (left+1) *x - right *x , left+1 > right 同理不成立

// 进行推论:
// 在固定区间, 进行聚合中心点的推断时
// 在聚合点只改变一个坐标的情况下, 影响最终结果的是 左边和右边的点数
// 因此除了中心点, 聚合点向任何一边偏移都不可能导致总位移量减少

class Solution2
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        // 记录1的坐标
        vector<int> pos;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == 1)
                pos.push_back(i);

        //  p 是 k 的二分之一
        int p = k / 2;

        //  当 k 为奇数的时候 left == right
        //  当 k 为偶数的时候 left == right + 1
        int left = k / 2, right = k - k / 2 - 1;

        // 计算第一次数字
        // pos[i]- i 就是中间 0 的个数
        // [1,1,0,1], k = 2, p = 1

        // i 是中间差的 1 的个数
        // pos[p] - p[p-1] 就是位置 p 号1 到 p-1 号 1 的坐标差
        // pos[p] - p[p-1] -1 就是 p 号1 到 p-1 号1 中间的0 的个数

        long long val = 0;
        for (int i = 1; i <= left; ++i)
            val += pos[p] - pos[p - i] - (i);
        for (int i = 1; i <= right; ++i)
            val += pos[p + i] - pos[p] - (i);
        // 计算出了以 k/2 号1 为中心, 0号1 到 k-1号1区间的挪动距离

        long long best = val;

        // 以继续以 p 为中心
        for (p++; p + right < pos.size(); ++p)
        {
            // p - 1 => p
            // 减去最左边的位移量
            val -= pos[p - 1] - pos[p - 1 - left] - left;

            // 加上全部偏移量
            val += (left - right) * (pos[p] - pos[p - 1] - 1);

            // 加上最右边的位移量
            val += pos[p + right] - pos[p] - right;
            best = min(best, val);
        }
        return best;
    }
};