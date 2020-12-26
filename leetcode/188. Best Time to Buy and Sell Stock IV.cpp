/* 
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 

Constraints:

    0 <= k <= 109
    0 <= prices.length <= 104
    0 <= prices[i] <= 1000


*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k == 0 || prices.size() == 0)
            return 0;

        int len = prices.size();
        // 在k非常大, 足够进行最多次交易的时候使用快速解法
        if (k > len / 2)
            return quickSolve(prices);

        // 创建两个数列用来进行DP算法
        vector<int> buy(k + 1, INT_MIN); // 表示进行第 k 次买入时可以获得的最大收益
        vector<int> sell(k + 1, 0);      // 表示进行第 k 次卖出时可以获得的最大收益

        // 外层对当前判断的股票进行遍历
        for (int i_stock = 0; i_stock < prices.size(); i_stock++)
        {
            // 内圈对交易次数进行遍历
            for (int k_trans = 1; k_trans <= k; k_trans++)
            {
                // 对于每次交易 使用该算式来获得最低买入价
                // 因为初始值是 INT_MIN 所以第一次遍历都会成为 -prices[0]
                buy[k_trans] = max(buy[k_trans], sell[k_trans - 1] - prices[i_stock]);

                // 获得最高卖出收益
                sell[k_trans] = max(sell[k_trans], buy[k_trans] + prices[i_stock]);

                // 不会引起冲突 很神奇

                /* 
                第一次外层循环执行完成后 所有 buy 都是 -prices[0]             所有 sell 都是 0  对于股票天数只有1的时候有鲁棒性
                第二次外层循环执行完成后 所有 buy 都是两天中更便宜的买入价格    所有 sell 都是 0 或者前两天的差价

                第三次外层循环时         buy[1]是前三天最便宜的买入价    sell[1] 是0 或者前三天最大差价
                                        buy[2]需要考虑 sell[1]的影响开始变化  
                                        不管sell[1]是0还是前三天最大差价  buy[2]减去prices[2] 后 sell[2]又加回来 sell[2]==sell[1]
                                        再往后的sell同理相同

                第四次外层循环时         buy[1]还是前四天最便宜买入价   sell[1] 还是是0 或者最大差价
                                        buy[2]受sell[1]影响  如果 sell[1]的差价使用的是第一二天的差价
                                        且 prices[3]>prices[2] 那么 buy[2]和第三层循环的buy[2]相同=sell[1]-prices[2]
                                        sell[2]=sell[1]+prices[3]-prices[2]= 完整两次卖出
                */

                /* 
                假设 buy[k] 的计算结果是后者    sell[k - 1]-prices[i]
                那么 sell[k]的计算结果则是      max(sell[k],sell[k-1])
                意思就是维持原值或者不发生交易
                */
            }
        }

        return sell[k];
    }

    // 因为不限制交易次数 而且不需要保留交易过程
    // 因此只要有任何的价格差, 都可以通过某种交易过程获益
    int quickSolve(vector<int> &prices)
    {
        int maxProfit = 0;

        int len = prices.size();
        for (int i = 1; i < len; i++)
        {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
};