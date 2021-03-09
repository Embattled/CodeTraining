// 别人的方法
class Solution
{
    typedef pair<int, int> PII;

public:
    int countRestrictedPaths(int n, vector<vector<int>> &E)
    {
        long mod = 1e9 + 7;
        // 合并了下一个边以及边权
        vector<vector<pair<long, int>>> G(n);
        for (auto &e : E)
        {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }

        vector<long> dist(n, INT_MAX);
        vector<long> cnt(n, 0);

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        auto cmp = [&dist](int a, int b) { return dist[a] > dist[b]; };
        priority_queue<int, deque<int>, decltype(cmp)> q(cmp);

        dist[n - 1] = 0;
        cnt[n - 1] = 1;
        // pq.emplace(0, n - 1);
        q.push(n-1);
        vector<bool> check(n, false);
        // while (pq.size())
        while (q.size())
        {
            // auto [w, u] = pq.top();
            // pq.pop();
            auto u = q.top();
            q.pop();

            auto w = dist[u];
            if (check[u])
                continue;
            check[u] = true;
            for (auto &[v, d] : G[u])
            {
                if (dist[v] > w + d)
                {
                    dist[v] = w + d;
                    // pq.emplace(dist[v], v);
                    q.emplace(dist[v], v);
                }
                if (w > dist[v])
                {
                    cnt[u] = (cnt[u] + cnt[v]) % mod;
                }
            }
        }
        return cnt[0];
    }
};


// 修改后的自己的方法
class Solution
{
public:
    int mod = 1000000007;
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> ed(n + 1);
        map<pair<int, int>, int> edm;
        for (auto &e : edges)
        {
            ed[e[0]].push_back(e[1]);
            ed[e[1]].push_back(e[0]);
            edm[make_pair(e[0], e[1])] = e[2];
            edm[make_pair(e[1], e[0])] = e[2];
        }
        vector<int> dis(n + 1, INT_MAX);
        dis[n] = 0;
        vector<long long> path(n + 1, 0);
        path[n] = 1;

        // 由于数字的改变， 会导致新的元素插入位置错误， 不能这么写
        // auto cmp = [&dis](int a, int b) { return dis[a] > dis[b]; };
        // priority_queue<int, deque<int>, decltype(cmp)> q(cmp);
        
        
        priority_queue<pair<int,int>,deque<pair<int,int>>,greater<pair<int,int>>> q;

        q.push(make_pair(dis[n],n));
        vector<bool> check(n + 1, false);

        while (!q.empty())
        {
            auto [_,now] = q.top();
            q.pop();
            if (check[now])
                continue;
            check[now] = true;

            for (auto e : ed[now])
            {
                int d = dis[now] + edm[make_pair(e, now)];
                if (d < dis[e])
                {
                    dis[e] = d;
                    // 依据更新时候的 dis 进行排序， 被其他路线更新了也不会影响 queue 的有序性
                    q.push(make_pair(d,e));
                }
                //  这两个获取值的方法都可以 accepted
                // if (dis[now] > dis[e])
                // {
                //     path[now] = (path[e] + path[now]) % mod;
                // }
                if (dis[now] < dis[e])
                {
                    path[e] = (path[e] + path[now]) % mod;
                }
            }
        }

        return path[1] % mod;
    }
};
