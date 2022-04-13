#include <stack>
#include <queue>
#include <set>
#include <array>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;

typedef vector<int> vi;
typedef vector<vector<int>> vi2d;
typedef vector<ll> vl;
typedef vector<vector<ll>> vl2d;
typedef vector<char> vc;
typedef vector<vector<char>> vc2d;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()

int mov[] = {1, 0, -1, 0, 1};
int h, w;

const ll mod = 998244353;
bool check(int x, int y)
{
    if (x < 0 || x >= h || y < 0 || y >= w)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ll ans = 0;

    int n, m;
    cin >> n >> m;

    vi2d edge(n + 1);
    rep(0, i, m)
    {
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    int N = 1 << n;
    vi2d dp(N, vi(n + 1, INT_MAX));

    queue<pii> Q;
    repe(1, i, n)
    {
        int s = 1 << (i - 1);
        dp[s][i] = 1;
        Q.push(mp(s, i));
    }

    while (!Q.empty())
    {
        auto [s, v] = Q.front();
        Q.pop();

        for (auto np : edge[v])
        {
            int ns = s ^ (1 << (np-1));
            if (dp[ns][np] < INT_MAX)
                continue;
            dp[ns][np] = dp[s][v] + 1;
            Q.push(mp(ns, np));
        }
    }

    rep(1, s, N)
    {
        int inf = INT_MAX;
        repe(1, p, n)
        {
            inf = min(inf, dp[s][p]);
        }
        ans += inf;
    }
    cout << ans << endl;
    return 0;
}
