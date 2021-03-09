// Heltion's method.

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {

        // 入度列表
        vector<int> d(n);
        for (auto &e : edges)
        {
            // 坐标修正
            e[0] -= 1;
            e[1] -= 1;
            d[e[0]] += 1;
            d[e[1]] += 1;
        }
        // 复制一份
        vector<int> v = d;

        // 升序排序
        sort(v.begin(), v.end());

        // mp 统计重复的边
        map<pair<int, int>, int> mp;
        for (auto &e : edges)
        {
            if (e[0] > e[1])
                swap(e[0], e[1]);
            mp[{e[0], e[1]}] += 1;
        }
        vector<int> res;
        for (int x : queries)
        {

            int ans = 0;

            // i 正常 +1 , j 是持续左移
            for (int i = 0, j = (int)v.size() - 1; i < v.size(); i += 1)
            {
                // 移动范围是只考虑 入度和满足条件
                // 在 左边为 i的情况下 j 左移到入度和小于等于 query
                while (j >= 0 and v[i] + v[j] > x)
                    j -= 1;
                // ans 先加上 j右边元素的个数
                ans += (int)v.size() - 1 - j;
            }

            // 消除重复项, 消除不存在的两点重复项
            for (int i = 0; i < n; i += 1)
                if (d[i] + d[i] > x)
                    ans -= 1;

            // 因为没限制 i<j 因此统计了2倍
            ans = ans / 2;

            // 对边不符合的情况进行清除
            for (auto &[z, y] : mp)
            {
                if (d[z.first] + d[z.second] > x and d[z.first] + d[z.second] - y <= x)
                    ans -= 1;
            }
            res.push_back(ans);
        }
        return res;
    }
};

// Learned Heltion's method and rectify my own method
class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int en = edges.size();
        vector<int> in(n + 1, 0);
        map<pair<int, int>, int> ed;
        for (auto &edge : edges)
        {
            in[edge[0]]++;
            in[edge[1]]++;

            if (edge[0] > edge[1])
                swap(edge[0], edge[1]);
            ed[make_pair(edge[0], edge[1])]++;
        }
        auto in2 = in;
        sort(in2.begin(), in2.end());
        vector<int> res;
        for (auto &query : queries)
        {
            int r = 0;

            for (int i = 1, j = n; i <= n; i++)
            {
                while (j > i && in2[i] + in2[j] > query)
                    j--;
                r += n - max(i, j);
            }

            for (auto &[a, b] : ed)
            {
                if (in[a.first] + in[a.second] > query && in[a.first] + in[a.second] - b <= query)
                {
                    r--;
                }
            }
            res.push_back(r);
        }
        return res;
    }
};

// Fastest method
class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        // 入度 array
        vector<int> f(n);

        // 统计重复边
        map<pair<int, int>, int> egs;
        
        // 统计入度和边
        for (auto &e : edges)
        {
            int a = e[0] - 1, b = e[1] - 1;
            f[a] += 1;
            f[b] += 1;
            egs[make_pair(min(a, b), max(a, b))] += 1;
        }
        
        // 出度为 key 的顶点有多少个
        map<int, int> cfo; // count of fan-out
        for (int i = 0; i < n; ++i)
            cfo[f[i]] += 1;

        vector<int> s(edges.size() * 2 + 1, 0);
        // 总共组合数
        int comb = n * (n - 1) / 2;

        // 对于所有出度的可能
        for (auto &it : cfo)
        {
            // 对于所有出度的可能
            for (auto &it2 : cfo)
            {
                // s的 index 就是两个点的出度和
                // 排列
                if (it.first == it2.first)
                    s[it.first * 2] += it.second * (it.second - 1);
                else
                    s[it.first + it2.first] += it.second * it2.second;
            }
        }

        // 修正所有边
        for (auto &e : egs)
        {
            int a = e.first.first, b = e.first.second;
            int v = f[a] + f[b];
            // 入度合
            s[v] -= 2;
            // 边的个数
            s[v - e.second] += 2;
        }

        // 排列降为组合
        // s变为累加数列
        s[0] /= 2;
        for (int i = 1; i < s.size(); ++i)
        {
            s[i] = s[i] / 2 + s[i - 1];
        }

        vector<int> ans;
        for (int q : queries)
        {
            // 答案就是全部组合数减去 s[q]
            ans.push_back(comb - s[q]);
        }
        return ans;
    }
};