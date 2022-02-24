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

bool check(int x, int y)
{
    if (x < 0 || x >= h || y < 0 || y >= w)
    {
        return true;
    }
    return false;
}

unordered_set<int> pfact(int x)
{
    unordered_set<int> res;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            res.insert(i);
        }
    }
    if (x != 1)
    {
        res.insert(x);
    }
    return res;
}


int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;

    vi a(n);
    vector<bool> isprim(m + 1, true);

    rep(0, i, n)
    {
        cin >> a[i];

        auto v=pfact(a[i]);
        for(auto &nx : v) {
            if(isprim[nx]) {
                for(int j=nx; j<=m; j+=nx) {
                    isprim[j]=false;
                }
            }
        }
    }


    // result part
    vi res;
    for (int i = 1; i <= m; i++)
    {
        if (isprim[i])
        {
            res.pb(i);
        }
    }
    cout << res.size() << endl;
    for (auto &r : res)
    {
        cout << r << endl;
    }

    return 0;
}
