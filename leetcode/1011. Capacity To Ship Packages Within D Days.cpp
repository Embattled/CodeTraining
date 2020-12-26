/* 
A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 

*/

class Solution
{
public:
    bool bin(vector<int> &weights, int d, long long int mid)
    {
        int daysUsed = 1, packages = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + packages > mid)
            {
                daysUsed++;
                packages = weights[i];
                if (daysUsed > d)
                    return false;
            }

            else
            {
                packages += weights[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int> &weights, int D)
    {
        long long int sumPackage = 0, biggestWeight = INT_MIN, ans = INT_MAX;
        for (int i = 0; i < weights.size(); i++)
        {
            sumPackage += weights[i];
            if (weights[i] > biggestWeight)
                biggestWeight = weights[i];
        }
        // biggest 是一个包裹大小的下限 而sumPackage是上限
        while (biggestWeight <= sumPackage)
        {
            long long int mid = biggestWeight + (sumPackage - biggestWeight) / 2;
            if (bin(weights, D, mid))
            {
                ans = min(mid, ans);
                // 上限更改为 之前计算合理的 mid值的 mid-1
                sumPackage = mid - 1;
            }

            else
            {
                // 下限提高到 mid +1
                biggestWeight = mid + 1;
            }
        }
        return ans;
    }
};