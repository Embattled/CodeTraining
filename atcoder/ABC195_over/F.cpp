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
#define allof(a) (a).begin(), (a).end()

int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;

    ll primes[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    int lenp = sizeof(primes) / sizeof(ll);

    vector<ll> dp(1 << lenp, 0);
    dp[0] = 1;

    for (ll num = a; num <= b; num++)
    {
        int bit = 0;
        for (int j = 0; j < lenp; j++)
        {
            if (num % primes[j] == 0)
            {
                bit |= 1 << j;
            }
        }
        for (int st = 0; st < (1 << lenp); st++)
        {
            if ((st & bit) == 0)
            {
                dp[st | bit] += dp[st];
            }
        }
    }
    ll ans = 0;
    for (ll nst : dp)
    {
        ans += nst;
    }
    cout << ans << endl;
    return 0;
}
