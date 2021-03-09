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
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define mp make_pair
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)

const int mod = 1e9 + 7;
inline int addmod(int x)
{
    return x >= mod ? x - mod : x;
}
int h2d(char c)
{
    if (c >= 'A')
    {
        return c - 'A' + 10;
    }
    return c - '0';
}

string s;
int n, k;

vector<int> cnt(1 << 16, 0);
vector<vector<int>> dp;

// x代表组合
// dep 代表深度 x 代表当前状态集, lim为真代表前段有小于s的, zero为真代表前段的非全0
int dfs(int dep, int x, bool lim, bool zero)
{
    // 越界
    if (dep == n)
        // 成功就返回1
        return cnt[x] == k;

    // lim==false or zero==false
    // 进行更深度搜索, 这里面的值都不全面, 不能作为 dp进行保存
    if (!lim || !zero)
    {
        // 取出 s[dep]
        // lim为真则 mx = 15, 否则等于 s[dep]
        // lim为真则代表上一位小于 s[dep-1], 因此这一位可以随意取值
        // lim为假则代表前面所有遍历的等于 s
        int mx = lim ? 15 : h2d(s[dep]);
        int ans = 0;

        // 遍历每个数字
        for (int i = 0; i <= mx; i++)
        {
            // xx 保存新状态
            int xx = x;
            // 如果 zero!=0 或者 i!=0
            // 即当 i==0 的时候, 只有 zero 为真才会赋予 xx |= 1, 即允许使用数字 0作为一种数字
            if (zero || i)
                xx |= (1 << i);

            // 深度 +1 , 传入新的 xx组合, lim 一旦为真就无法返回, zero一旦为真同样
            // zero == 0 代表前排一直为0的情况
            // i< mx 则递归的 lim 为真, 代表往后的位可以随意取值
            ans = addmod(ans + dfs(dep + 1, xx, lim || i < mx, zero || i > 0));
        }

        // 直接返回答案
        // 因为这里不是完全搜索, 所以不能保存到 dp
        return ans;
    }
    // lim ==true && zero==true
    // 即代表前段数字非全零并且小于s
    // 开始正常搜索

    // 已遍历则不用再去递归
    if (dp[dep][cnt[x]] != -1)
        return dp[dep][cnt[x]];

    int ans = 0;
    // x| 1<<(0~15)
    for (int i = 0; i <= 15; i++)
        // 此后面的搜索也都是正常搜索
        ans = addmod(ans + dfs(dep + 1, x | (1 << i), true, true));

    // 赋值后返回
    return dp[dep][cnt[x]] = ans;
}
int main()
{
    
    // cnt 即二进制数对应的 K 值
    for (int i = 1; i < 1 << 16; i++)
        cnt[i] = cnt[i / 2] + i % 2;

    cin >> s >> k;
    n = s.length();
    dp.resize(n, vector<int>(17, -1));

    cout << dfs(0, 0, false, false) << endl;
    return 0;
}