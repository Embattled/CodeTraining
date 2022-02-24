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
    int n;
    cin >> n;

    vc2d s(n, vc(n)), t(n, vc(n));

    pii smin = mp(n, n), smax = mp(0, 0);
    pii tmin = smin, tmax = smax;

    int sn = 0, tn = 0;
    rep(0, i, n)
    {
        rep(0, j, n)
        {
            cin >> s[i][j];
            if (s[i][j] == '#')
            {
                sn++;
                smin.fr = min(smin.fr, i);
                smin.sc = min(smin.sc, j);

                smax.fr = max(smax.fr, i);
                smax.sc = max(smax.sc, j);
            }
        }
    }

    rep(0, i, n)
    {
        rep(0, j, n)
        {
            cin >> t[i][j];
            if (t[i][j] == '#')
            {
                tn++;
                tmin.fr = min(tmin.fr, i);
                tmin.sc = min(tmin.sc, j);

                tmax.fr = max(tmax.fr, i);
                tmax.sc = max(tmax.sc, j);
            }
        }
    }
    if (tn != sn)
    {
        cout << "No" << endl;
        return 0;
    }

    pii lens = mp(smax.fr - smin.fr + 1, smax.sc - smin.sc + 1);
    pii lent = mp(tmax.fr - tmin.fr + 1, tmax.sc - tmin.sc + 1);

    if (lens.fr == lent.fr && lens.sc == lent.sc)
    {
        bool succ[2] = {true, true};
        rep(0, i, lent.fr)
        {
            rep(0, j, lent.sc)
            {
                if (s[smin.fr + i][smin.sc + j] != t[tmin.fr + i][tmin.sc + j])
                {
                    succ[0] = false;
                    break;
                }
            }
        }
        rep(0, i, lent.fr)
        {
            rep(0, j, lent.sc)
            {
                if (s[smax.fr - i][smax.sc - j] != t[tmin.fr + i][tmin.sc + j])
                {
                    succ[1] = false;
                    break;
                }
            }
        }

        if (succ[0] || succ[1])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (lens.sc == lent.fr && lens.fr == lent.sc)
    {
        bool succ[2] = {true, true};
        rep(0, i, lent.fr)
        {
            rep(0, j, lent.sc)
            {
                if (s[smin.fr + j][smax.sc - i] != t[tmin.fr + i][tmin.sc + j])
                {
                    succ[0] = false;
                    break;
                }
            }
        }
        rep(0, i, lent.fr)
        {
            rep(0, j, lent.sc)
            {
                if (s[smax.fr - j][smin.sc + i] != t[tmin.fr + i][tmin.sc + j])
                {
                    succ[1] = false;
                    break;
                }
            }
        }

        if (succ[0] || succ[1])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
