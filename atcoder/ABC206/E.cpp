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
typedef vector<ll> vl;

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

int main(int argc, char const *argv[])
{
    int l, r;
    cin >> l >> r;

    ll res = 0;

    // sieve of eratosthenes
    vi prime(1e6 + 1, 0);
    repe(2, i, r)
    {
        if (prime[i] != 0)
            continue;
        for (ll j = i; j <= r; j += i)
        {
            prime[j]++;
        }
        ll li=i;
        li *=li;
        for(ll j=li;j<=r;j+=li){
            prime[j] = INT_MIN;
        }
    }
    // 2 的时候计算过的
    // 6 12 18 24
    // 3 的时候也计算过的
    // 6 12 18 24
    // 所以 2*3 的6 要减去

    // 同理
    // 2 3 5 三个因子 = 30
    // 30 60 90
    // 2 3 5的时候加上了, 6 15 10 的时候又减去了
    // 所以 30 作为因子的时候要加


    // 对于 prime[i]= s 来说

    // 质数 i : prime [i]=0
    // 包含两个以及以上相同质因子的数 prime[i]=INT_MIN
    // 普通数 : prime[i] = 质因子的个数
    repe(2, i, r)
    {
        // 两个相同的不做统计  4 9 25
        if (prime[i] <= 0)
        {
            continue;
        }

        // 对于一个普通数
        // 计算得出在范围中的倍数个数
        // 组合数即为 c*(c-1)/2
        ll c = (r / i) - ((l - 1) / i);

        // 如果质因子的个数是奇数， 则加
        // 2 3 5  30
        if (prime[i] % 2)
        {
            res += c * (c - 1) / 2;
        }
        // 如果质因子的个数是偶数， 则减 
        // 6 10
        else
        {
            res -= c * (c - 1) / 2;
        }
    }
    // minus x=g
    repe(max(2, l), i, r)
    {
        res -= (r / i) - 1;
    }
    cout << 2 * res << endl;
    return 0;
}
