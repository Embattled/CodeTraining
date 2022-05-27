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
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> points(n);

    rep(0, i, n)
    {
        ll x, y;
        cin >> x >> y;
        points[i] = mp(x, y);
    }

    if (k == 1)
    {
        cout << "Infinity" << endl;
        return 0;
    }
    int ans = 0;

    vi2d check(n, vi(n, 0));

    rep(0, i, n)
    {
        rep(i + 1, j, n)
        {
            if (check[i][j])
                continue;
            check[i][j] = 1;

            auto [xi, yi] = points[i];
            auto [xj, yj] = points[j];

            int np = 2;
            vi lis{i,j};
            if (xi == xj)
            {
                rep(j + 1, l, n)
                {
                    auto [xl, yl] = points[l];
                    if (xl == xi)
                    {
                        np++;
                        for(auto pline:lis){
                            check[pline][l]=1;
                        }
                        lis.pb(l);
                    }
                }
            }
            else if (yi == yj)
            {
                rep(j + 1, l, n)
                {
                    auto [xl, yl] = points[l];
                    if (yl == yi)
                    {
                        for(auto pline:lis){
                            check[pline][l]=1;
                        }
                        lis.pb(l);
                        np++;
                    }
                }
            }
            else
                rep(j + 1, l, n)
                {
                    auto [xl, yl] = points[l];
                    if ((xi - xj) * (yj - yl) == (xj - xl) * (yi - yj))
                    {
                        for(auto pline:lis){
                            check[pline][l]=1;
                        }
                        lis.pb(l);
                        np++;
                    }
                }
            if (np >= k)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
