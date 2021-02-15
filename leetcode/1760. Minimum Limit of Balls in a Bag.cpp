class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int lo = 0;
        int hi = 1e9 + 7;
        while (lo + 1 < hi)
        {
            // 为什么是二分查找
            // 直接假设 maximum 是 mid
            int mid = lo + (hi - lo) / 2;
            
            // move
            // 达成 maximum 是 mid 需要的操作次数
            long long moves = 0;
            
            // 对于每个 num
            for (int x : nums)
            {
                // 求出需要将该数分解到 小于等于 mid 需要的次数
                moves += (x - 1) / mid;
                
                // 只用一次不需要增加 move
                // --moves;
            }

            
            // 如果该操作不会越界
            if (moves <= maxOperations)
            {
                // 最高值变为 mid
                hi = mid;
            }
            else
            {
                // 最低值变为 mid
                lo = mid;
            }
        }

        return hi;
    }
};