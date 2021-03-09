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

#define mp make_pair
#define ft first
#define sd second


// 超快速度的得到一个数的所有因子
vector<ll> div(ll n)
{
    vector<ll> ret;

    // 必定有 1 的因子
    ret.push_back(1);
    // 遍历 n
    for (ll i = 2; n != 1; i++)
    {
        // 求因子只用求到 开方 n 
        if (i * i > n)
            i = n;

        // 能够整除
        if (n % i == 0)
        {
            // 同一个因数多次被除
            // 直到该数不存在 i 的因子
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }

            // ret 的大小
            int sz = ret.size();

            // 对于原本 ret 中的每个值
            for (int t = 0; t < sz; t++)
            {
                ll x = ret[t];
                // 每个值都乘以该 i 因子 n 次
                // 得到该数所有可能的因子数
                for (int j = 0; j < cnt; j++)
                {
                    x *= i;
                    ret.push_back(x);
                }
            }
        }
    }
    return ret;
}


// 交换算法求 gcd  
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    ll n;
    ll a[2002];
    ll m = 1000000000;

    cin >> n;
    // 先求出最小值
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m = min(m, a[i]);
    }

    // buffer
    map<ll, ll> M;


    // 注意这里的遍历
    // 对所有的数的所有因子进行遍历
    for (int i = 0; i < n; i++)
    {
        // 获得 a[i] 的因子 array
        vector<ll> vec = div(a[i]);

        // 对于 a[i] 的所有因子, 其中肯定包含了 a[i]自身和 1
        for (ll d : vec)
        {
            // d 不存在则 M[d] = a[i]
            // 代表该因子可以从 a[i] 得来
            // 但是不确定能否最终剩余到这个因子
            if (M.find(d) == M.end())
            {
                M[d] = a[i];
            }
            else
            {
                // M[d] 已经存在, 代表两个数都有同一个因子
                // M[d] = gcd 原本的值和新 a[i]
                // 对这两个数进行 gcd 运算
                M[d] = gcd(M[d], a[i]);
            }
        }
    }
    // 最小值的情况
    int ret = 1;
    for (auto p : M)
    {
        // 只有 M 中的索引和值相等的时候 ret++
        // 代表 可以通过 gcd 运算得到这个值
        // 而且必须比最小值小
        if (p.ft == p.sd && p.ft < m)
            ret++;
    }
    cout << ret << endl;

    return 0;
}
