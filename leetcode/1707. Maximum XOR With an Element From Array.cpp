class Solution
{
public:
    class trieNode
    {
    public:
        trieNode *t[2];
        trieNode()
        {
            t[0] = nullptr;
            t[1] = t[0];
        }
    };

    void search(trieNode *root, int &res, int x, int m, int bit, int nowValue, bool edge)
    {
        if (bit == 0)
        {
            res = max(res, nowValue);
            return;
        }

        // 取出该位的数字
        int vx = x & bit ? 1 : 0;
        int vm = m & bit ? 1 : 0;

        // 剪枝法
        if ((nowValue | bit | (bit - 1)) <= res)
            return;

        // 取出能让 xor 较大的那个数字
        int big = 1 ^ vx;

        // 是否为边缘状态分别判断
        if (edge)
        {
            if (root->t[big] && big <= vm)
            {
                search(root->t[big], res, x, m, bit >> 1, nowValue | bit, edge && (big == vm));
            }
            if (root->t[1 - big] && (1 - big) <= vm)
            {
                search(root->t[1 - big], res, x, m, bit >> 1, nowValue, edge && ((1 - big) == vm));
            }
        }
        else
        {
            if (root->t[big])
            {
                search(root->t[big], res, x, m, bit >> 1, nowValue | bit, edge && (big == m));
            }
            if (root->t[1 - big])
            {
                search(root->t[1 - big], res, x, m, bit >> 1, nowValue, edge && ((1 - big) == m));
            }
        }
    }

    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int nq = queries.size();
        vector<int> res(nq, -1);

        trieNode *head = new trieNode();

        for (auto &num : nums)
        {
            int bit = 1 << 30;

            auto p = head;
            while (bit != 0)
            {
                int val = (num & bit) > 0 ? 1 : 0;

                if (p->t[val] == nullptr)
                {
                    p->t[val] = new trieNode();
                }
                p = p->t[val];
                bit = bit >> 1;
            }
        }
        int index = 0;
        int bit = 1 << 30;
        for (auto &q : queries)
        {
            search(head, res[index++], q[0], q[1], bit, 0, true);
        }

        return res;
    }
};