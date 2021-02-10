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
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define ft first
#define sd second

vector<ll> div(ll n)
{
    vector<ll> ret;
    ret.push_back(1);
    for (ll i = 2; n != 1; i++)
    {
        if (i * i > n)
            i = n;
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            int sz = ret.size();
            for (int t = 0; t < sz; t++)
            {
                ll x = ret[t];
                for (int j = 0; j < cnt; j++)
                {
                    x *= i;
                    ret.push_back(x);
                }
            }
        }
    }
    return ret;
}

ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    ll n;
    ll a[2002];
    ll m = 1000000000;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m = min(m, a[i]);
    }
    map<ll, ll> M;

    for (int i = 0; i < n; i++)
    {
        vector<ll> vec = div(a[i]);
        for (ll d : vec)
        {
            if (M.find(d) == M.end())
            {
                M[d] = a[i];
            }
            else
            {
                M[d] = gcd(M[d], a[i]);
            }
        }
    }
    int ret = 1;
    for (auto p : M)
    {
        if (p.ft == p.sd && p.ft < m)
            ret++;
    }
    cout << ret << endl;

    return 0;
}
