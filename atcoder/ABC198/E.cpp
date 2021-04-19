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

vi ans;
void cal(int father, int now, vector<bool> &col, vector<vector<int>> &path, vi &colors)
{
    bool ex = col[colors[now]];

    if (!ex)
    {
        ans.pb(now);
        col[colors[now]] = true;
    }
    for (int next : path[now])
    {
        if (next == father)
            continue;
        cal(now, next, col, path, colors);
    }
    if(!ex){
        col[colors[now]] = false;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vi colors(n + 1, 0);
    vi used(n + 1, 0);
    repe(1, i, n)
    {
        cin >> colors[i];
    }

    vector<vector<int>> path(n + 1);
    rep(1, i, n)
    {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<bool> col(100001, false);
    cal(0, 1, col, path, colors);
    sort(ans.begin(), ans.end());
    for (int r : ans)
    {
        cout << r << endl;
    }

    return 0;
}
