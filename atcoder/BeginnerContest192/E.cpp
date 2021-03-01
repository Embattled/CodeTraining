#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mp make_pair
#define fr first
#define sc second

int main()
{

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;


    vector<pair<int, pair<int, int>>> G[N+1];
    vector<ll> dist(N+1,LLONG_MAX);
    for (int i = 0; i < M; i++)
    {
        int u, v, t, k;
        cin >> u >> v >> t >> k;
        G[u].push_back(make_pair(v, make_pair(t, k)));
        G[v].push_back(make_pair(u, make_pair(t, k)));
    }

    dist[X] = 0;

    priority_queue<pair<ll, int>> P;
    P.push(make_pair(0, X));
    
    while (!P.empty())
    {
        int u = P.top().second;
        long cost = -P.top().first;
        P.pop();
        if (dist[u] < cost)
            continue;
        for (pair<int, pair<int, int>> e : G[u])
        {
            int v = e.first;
            int t = e.second.first;
            int k = e.second.second;
            long nxt = (cost + k - 1) / k * k + t;
            if (dist[v] > nxt)
            {
                dist[v] = nxt;
                P.push(make_pair(-nxt, v));
            }
        }
    }
    long ans = dist[Y];
    if (ans == (long)9e18)
        ans = -1;
    cout << ans << endl;
}
/*
int main2()
{

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (m == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> t_reach(n + 1, LLONG_MAX);

    vector<pair<int, int>> t_t(m);
    vector<bool> instack(n + 1, false);
    vector<vector<pair<int, int>>> rail(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, T, K;
        cin >> a >> b >> T >> K;

        t_t[i].fr = K;
        t_t[i].sc = T;

        rail[a].push_back(mp(b, i));
        rail[b].push_back(mp(a, i));
    }

    auto cmp = [t_reach](int a, int b) { return t_reach[a] > t_reach[b]; };

    priority_queue<ll, deque<ll>, decltype(cmp)> q(cmp);
    // priority_queue<ll, deque<ll>, decltype(cmp)> q(cmp);

    // queue<int> q;
    q.push(x);
    t_reach[x] = 0;
    instack[x] = true;

    while (!q.empty())
    {
        // int now = q.front();
        // printqueue(q,t_reach);
        int now = q.top();
        instack[now] = false;
        q.pop();

        ll nowt = t_reach[now];

        for (auto d : rail[now])
        {
            int road = d.sc;
            int dest = d.fr;

            ll nowreach = (nowt + t_t[road].fr - 1) / t_t[road].first * t_t[road].first + t_t[road].second;

            if (t_reach[dest] == LLONG_MAX || nowreach < t_reach[dest])
            {
                t_reach[dest] = nowreach;
                if (!instack[dest])
                {
                    q.push(dest);
                    instack[dest] = true;
                }
            }
        }
    }

    if (t_reach[y] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << t_reach[y] << endl;
    }

    return 0;
}
*/
/* 
N 个城市 1~N
M 条轨道 1~M 轨道双向




*/