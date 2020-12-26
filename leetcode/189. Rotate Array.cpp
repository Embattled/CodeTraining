/* 
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105


*/

// 自己的方法， 大调转转换成小调转
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        len = nums.size();
        k = k % len;
        if (k == 0)
            return;

        k_v = k;

        for (int count = 0; k > 0 && count < nums.size() - 1;)
        {

            for (int i = 0; (i < k) && (count < nums.size() - 1); i++)
            {
                int swapI = calIndex(i);
                swap(nums[i], nums[swapI]);
                count++;

                if (swapI == len - 1)
                {
                    int diff = len - k;

                    len = k;
                    k_v = k_v - diff;
                    k = k_v;
                    i = -1;
                }
            }
            k_v = k_v + k;
        }
    }

private:
    int k_v;
    int len;
    int calIndex(int &i)
    {
        return (i + k_v) % len;
    }
};

// 精简方法
void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}
