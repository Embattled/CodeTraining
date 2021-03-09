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
    ld x, y, rr;
    cin >> x >> y >> rr;

    // 将输入化为正数
    x += 200100.;
    y += 200100.;
    
    // 获取整数化的输入值
    // Each of X, Y, and R has at most four digits after the decimal point.
    ll X = 10000 * x + 0.5;
    ll Y = 10000 * y + 0.5;
    ll R = 10000 * rr + 0.5;

    ll ret = 0;


    // 从 最左边往10 到最右边加10
    // s = start
    for (ll s = x - rr - 10; s < x + rr + 10; s++)
    {
        
        // buttom 和 up
        ll b, u;

        // l 是最下边往10
        // r = y + 1
        ll l = y - rr - 10;
        ll r = y + 1;

        // 二分查找
        while (l < r)
        {
            // 取 l 到 r 的中点
            ll t = (l + r) / 2;

            // 计算出来的半径
            ll d = (s * 10000 - X) * (s * 10000 - X) + (t * 10000 - Y) * (t * 10000 - Y);

            // 小于
            if (d <= R * R)
                r = t;
            else
                l = t + 1;
        }
        // 计算出 buttom 

        b = l;
        l = y;

        r = y + rr + 10;
        // 同样二分查找
        while (l < r)
        {
            ll t = (l + r + 1) / 2;
            ll d = (s * 10000 - X) * (s * 10000 - X) + (t * 10000 - Y) * (t * 10000 - Y);
            if (d <= R * R)
                l = t;
            else
                r = t - 1;
        }
        // 计算出 up
        u = l;


        if (b <= u)
            // 添加结果
            ret += u - b + 1;
    }
    cout << ret << endl;

    return 0;
}