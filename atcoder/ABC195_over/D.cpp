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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pii> bags(n);
    vi box(m);
    rep(0, i, n)
    {
        int w, v;
        cin >> w >> v;
        bags[i] = mp(v, w);
    }
    sort(allof(bags), greater<pii>());
    rep(0, i, m)
    {
        cin >> box[i];
    }
    rep(0, query, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ll ans = 0;

        int total = m - (r - l + 1);
        int nu = 0;
        vector<bool> used(m, true);

        rep(0, bag, n)
        {
            int index = -1;
            int minsize = INT_MAX;

            rep(0, i, l)
            {
                if (used[i] && box[i] >= bags[bag].second && box[i] < minsize)
                {
                    index = i;
                    minsize = box[i];
                }
            }
            rep(r + 1, i, m)
            {
                if (used[i] && box[i] >= bags[bag].second && box[i] < minsize)
                {
                    index = i;
                    minsize = box[i];
                }
            }

            if (index != -1)
            {
                ans += bags[bag].first;
                used[index] = false;
                nu++;
            }
            if (nu == total)
            {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
