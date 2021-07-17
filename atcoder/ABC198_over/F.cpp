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

const ll mod = 998244353;

// quick power
ll qp(ll a, ll b)
{
  ll ans = 1;
  while (b)
  {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
ll c(ll n, ll m)
{
  ll r = 1;

  for (ll i = 1; i <= m; i++)
    r = r * ((n - i + 1) % mod) % mod * qp(i, mod - 2) % mod;
  return r;
}

ll n;

int main()
{
  cin >> n;
  n -= 6;
  ll r = 0;

  r = (r + c(n + 5, 5)) % mod;
  r = (r + 6ll * c(n / 2 + 3, 3) % mod) % mod;
  r = (r + 6ll * (4ll * c(n / 4 + 2, 2) % mod - 1ll * (3 - n % 4) * (n / 4 + 1) % mod + mod) % mod) % mod;
  if (n % 2 == 0)
    r = (r + 3ll * c(n / 2 + 2, 2) % mod) % mod;
  if (n % 3 == 0)
    r = (r + 8ll * (n / 3 + 1) % mod) % mod;
  r = 1ll * r * qp(24, mod - 2) % mod;

  cout << r << endl;
  return 0;
}