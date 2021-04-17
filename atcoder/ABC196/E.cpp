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

map<int, pair<bool, ll>> mapdata;
int n;

// nowv = now range lowest  value
void cal(int i, int start, ll nowv, ll addv, vl &a, vl &t, bool sv)
{
    if (i == n)
    {
        if (sv)
            mapdata[start] = mp(sv, nowv);
        else
            mapdata[start] = mp(sv, addv);
        return;
    }

    if (sv)
    {
        if (t[i] == 1)
        {
            nowv += a[i];
            cal(i + 1, start, nowv, 0, a, t, sv);
        }
        else if (t[i] == 2)
        {
            cal(i + 1, start, max(nowv, a[i]), 0, a, t, sv);
        }
        else
        {
            cal(i + 1, start, min(nowv, a[i]), 0, a, t, sv);
        }
    }
    else
    {
        if (t[i] == 1)
        {
            addv += a[i];
            cal(i + 1, start, nowv, addv, a, t, false);
        }
        else if (t[i] == 2)
        {
            if (nowv + addv >= a[i])
            {
                cal(i + 1, start, nowv, addv, a, t, false);
            }
            else
            {
                cal(i + 1, start, a[i], 0, a, t, true);
                cal(i + 1, a[i] - addv, a[i] - addv, addv, a, t, false);
            }
        }
        else
        {
            if (nowv + addv >= a[i])
            {
                cal(i + 1, start, a[i], 0, a, t, true);
            }
            else
            {
                cal(i + 1, start, nowv, addv, a, t, false);

                cal(i + 1, a[i] - addv, a[i], 0, a, t, true);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    vl a(n);
    vl t(n);
    rep(0, i, n)
    {
        cin >> a[i] >> t[i];
    }

    cal(0, -1e9, -1e9, 0, a, t, false);

    int q;
    cin >> q;

    for(auto res:mapdata){
        cout<<res.first<<"  "<<res.second.first<<" "<<res.second.second<<endl;
    }

    rep(0, i, q)
    {
        int x;
        cin >> x;

        auto res = --mapdata.upper_bound(x);

        if (res->second.first)
        {
            cout << res->second.second << endl;
        }
        else
        {
            cout << x + res->second.second << endl;
        }
    }

    return 0;
}




#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max() / 4;
void chmin(ll& a, ll b){ if(a > b) a = b; }
void chmax(ll& a, ll b){ if(a < b) a = b; }

int main(){
    ll N;
    cin >> N;
    ll low = -INF, high = INF, add = 0;
    for(ll i = 0; i < N; i++){
        ll A, T;
        cin >> A >> T;
        if(T == 1){
            low += A;
            high += A;
            add += A;
        }
        else if(T == 2){
            chmax(low, A);
            chmax(high, A);
        }
        else{
            chmin(low, A);
            chmin(high, A);
        }
    }
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i++){
        ll x;
        cin >> x;
        cout << clamp(x + add, low, high) << '\n';
    }
}
