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
typedef long double ld;

#define mp make_pair
#define fr first
#define sc second

ll m;
string x;
int ns;

bool check(ll n)
{
    ull a = 0;
    ull base = 1;

    bool baseout=false;
    for (int i = ns - 1; i >= 0; i--)
    {
        if (base > m||baseout)
        {
            return false;
        }
        a += (x[i] - '0') * base;

        if((ULLONG_MAX/base)<n){
            baseout=true;
        }

        base *= n;
        if (a > m)
        {
            // cout<<"wrong:"<<base<<"  num:"<<a<<endl;
            return false;
        }
    }
    // cout << "base:" << n << "ok" << endl;
    return true;
}

int main()
{

    cin >> x >> m;

    char d = '1';
    for (char c : x)
    {
        if (c > d)
        {
            d = c;
        }
    }
    ns = x.length();

    if (ns == 1 && (x[0] - '0') <= m)
    {
        cout << 1 << endl;
        return 0;
    }

    ll start = d - '0' + 1;
    ll end = 1e18;

    int res = 0;

    while (end > start)
    {
        ll mid = (end + start) / 2;
        // cout << "start:" << start << " end:" << end << "  mid:" << mid << endl;
        if (check(mid))
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if (!check(start))
    {
        start--;
    }

    // cout << "start:" << start << " end:" << end << endl;
    cout << start - (d - '0') << endl;

    return 0;
}
