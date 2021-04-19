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

const ll mod = 1e9 + 7;

ll mypow(ll base, ll p)
{
    if (base == 0)
        return 0;
    ll res = 1;

    while (p)
    {
        if (p & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        p >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ll n, p;
    cin >> n >> p;
    if (p == 2)
    {
        if(n==1){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    else
    {
        ll res = mypow(p - 2, n - 1);
        cout << ((p - 1) * res) % mod << endl;
    }

    return 0;
}
