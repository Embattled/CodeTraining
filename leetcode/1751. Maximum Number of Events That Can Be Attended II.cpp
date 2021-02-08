// 清晰算法， 但是时间长  1208ms 244mb
class Solution1
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();

        // 所有事件按开始时间排序 成表
        sort(events.begin(), events.end(), [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<int> start;
        for (auto &event : events)
        {
            start.emplace_back(event[0]);
        }

        // n 为核心的 dp 表
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // 逆序遍历
        for (int i = n - 1; i >= 0; i--)
        {

            // 获得能够在 events[i] 之后执行的事件的 列表索引
            int idx = upper_bound(start.begin() + i, start.end(), events[i][1]) - start.begin();

            // 在只考虑事件开始时间最后的 n-i 个事件的时候
            for (int j = 1; j <= k; j++)
            {
                // j=0 和 i=n 是0边界

                dp[i][j] = max(dp[i + 1][j], dp[idx][j - 1] + events[i][2]);
            }
        }

        return dp[0][k];
    }
};

// 最快算法 96ms
class Solution2
{
public:
    int maxValue(std::vector<vector<int>> &events, int k)
    {
        // 按照结束时间从小到大排序
        std::sort(events.begin(), events.end(),
                  [](const vector<int> &first, const vector<int> &second) -> bool {
                      return first[1] < second[1];
                  });

        const int n = events.size();

        // 二重DP， 第一索引是 事件数
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1,0));

        // 从0开始遍历
        for (int i = 0; i < n; ++i)
        {
            
            // 从 0 号事件到n-1号事件
            // 结束时间从低到高
            const vector<int> &event = events[i];

            // O(log events.length)  // AC 100 ms
            // 自定义查找算法提高速度
            auto it = std::lower_bound(

                // 反向迭代器搜索
                // 搜索起始位置是 从i的前一个元素开始
                std::next(events.rbegin(), n - i),
                // 到 0号事件之前结束
                events.rend(),
                event,
                [](const vector<int> &f, const vector<int> &eve) -> bool {
                    // 查找条件, 是否满足 结束时间大于等于该事件的开始时间
                    // 即， 查找结果是第一个 event[1]<events[i].0 的元素
                    return f[1] >= eve[0];
                });

            // 开始 id 
            auto prev_event_id = n - std::distance(events.rbegin(), it);

            // 同样 事件数的 1~k 遍历
            for (int visits = 1; visits <= k; ++visits)
            {
                
                dp[i + 1][visits] = std::max(dp[i][visits],
                event[2] + dp[prev_event_id][visits - 1]);
            }
        }

        // return *std::max_element(dp[event_count].begin(), dp[event_count].end());
        return dp[n][k];
    }
};
/* 

You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:

Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Example 2:

Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

Example 3:

Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.

 

Constraints:

    1 <= k <= events.length
    1 <= k * events.length <= 106
    1 <= startDayi <= endDayi <= 109
    1 <= valuei <= 106

 */