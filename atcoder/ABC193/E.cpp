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
#include <numeric>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl


ll gcd2 (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd2 (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
void test_case(int test) {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    ll l = x - q + 1;
    ll r = x + y - 1;
    l -= p;
    r -= p;
 
    show(l, r);
 
    ll mod = x * 2 + y * 2;
    const ll inf = 9e18;
    ll ans = inf;
    for (ll rem0 = l; rem0 <= r; ++rem0) {
        ll rem = (rem0 % mod + mod) % mod;
        ll d = gcd(p + q, mod);
        if (rem % d != 0) continue;

        ll x0, y0;
        gcd2((p + q) / d, mod / d, x0, y0);
        x0 *= rem / d;
        x0 = ((x0 % mod) + mod) % mod;
        ll val = mod / d;
        x0 %= val;
        show(mod, p+q, rem, x0, d);
        show(x0 * (p + q) % mod);
        // assert(x0 * (p + q) % mod == rem);
        ll cur = (p + q) * x0 + p;
        ll res = cur % (x * 2 + y * 2);
        show(rem, cur, res);
        if (res < x)
            cur += x - res;
        else if (res >= x + y)
            cur += x - res + (x * 2 + y * 2);
        ans = min(ans, cur);
    }
 
    if (ans == inf) {
        cout << "infinity\n";
    } else {
        cout << ans << '\n';
    }
}
 
int main() {
 
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}