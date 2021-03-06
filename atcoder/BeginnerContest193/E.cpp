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


// 输入的 a 是 人循环, b 是 车循环 
ll gcd2(ll a, ll b, ll &x, ll &y)
{
    // a 为 0 了后代表 b 是最大公倍数
    if (a == 0)
    {
        // x 是 0 
        x = 0;
        // 公倍数是 b * 1
        y = 1;
        // 返回 最大公倍数
        return b;
    }
    ll x1, y1;
    // 循环调用没毛病, 获得了最大公倍数
    // 递归结束的时候 x = 0 , y = 1
    ll d = gcd2(b % a, a, x1, y1);

    // x = 1 - 0 = 1
    // x = 0 - (公倍数/a) * 1
    x = y1 - (b / a) * x1;

    // y = 0 
    // 
    y = x1;

    // 继续返回最大公倍数
    return d;
}

//  判断一个情况
void test_case(int test)
{
    ll x, y, p, q;
    // x 路上时间
    // y 停车时间
    // p 睡觉时间
    // q 清醒时间
    cin >> x >> y >> p >> q;

    // x - p 是 车第一次到达B后 人已经清醒了多少秒(正数) 或者 还有多少秒清醒(负数)

    // x - p - q + 1 是还剩多少秒的清醒时间(负数) 或者 进入下一次睡眠的剩余时间 (负数) 或者已经进入了第二次睡眠多少秒 (正数)
    ll l = x - p - q + 1;

    // x + y - p + 1 是车从B往A返程的时候, 人已经清醒了多少秒(正数), 还剩多少秒第一次清醒 (负数)
    ll r = x - p + y + 1;

    // 一个轮回的时间
    ll mod = x * 2 + y * 2;

    const ll inf = 9e18;
    ll ans = inf;

    // 睡觉循环与 行车循环 的最大公倍数
    // 代表车或者人经历一次循环可以改变的最大的状态差值
    // 如果能整除, 即代表差值状态固定
    // d 等于 p+q 或者 mod
    ll d = gcd(p + q, mod);
    ll val = mod / d;
    
    // 获取除数的 gcd
    ll x0, y0;
    //
    gcd2((p + q) / d, mod / d, x0, y0);

    // 最多搜索1000次
    // 搜索一个差值
    for (ll rem0 = l; rem0 <= r; ++rem0)
    {
        // 获取一个正数的绝对值
        // 差值
        ll rem = (rem0 % mod + mod) % mod;

        // 不成立
        // 想要达成这个差值, rem % d 必须能整除
        if (rem % d != 0)
            continue;

        // 需要的数只有 x0
        // 获取整除的值并且乘给 x0
        x0 *= rem / d;
        x0 = ((x0 % mod) + mod) % mod;


        
        x0 %= val;

        // x0 次睡着醒后， x0+1 次清醒的时间
        ll cur = (p + q) * x0 + p;

        // 在这个时候车所处的一个循环的时间
        ll res = cur % mod;

        // 车在前往B的路上
        if (res < x)
            // x - res 是距离到达还剩余的时间
            cur += x - res;
        // 车在返程A 的路上
        else if (res >= x + y)
            // 距离从 A 出发的剩余时间 再加上 x
            cur += mod - res + x;

        // 最小值判断
        ans = min(ans, cur);
    }

    // 都不行
    if (ans == inf)
        cout << "infinity\n";
    else
        cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        test_case(test);
    }

    return 0;
}