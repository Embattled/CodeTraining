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

map<int, ll> st;
map<int, ll> ed;
vi colors;


// cal1 最快

// 最开始的代码 680 ms
ll cal0(int index, int place, vector<ll> &bufl, vector<ll> &bufr)
{
    if (index == colors.size())
    {
        return abs(place);
    }

    int t = colors[index];

    ll toend = 0;

    if (st[t] != ed[t])
    {
        ll dist = ed[t] - st[t];

        // 这里算是减少了计算量
        // 但是使得代码变复杂
        // 而且因为多重 if 导致最后的执行时间反而更长

        if (place < st[t])
        {
            if (bufr[index] == LLONG_MAX)
            {
                bufr[index] = cal0(index + 1, ed[t], bufl, bufr);
            }
            toend = bufr[index];
            toend += dist + st[t] - place;
        }
        else if (place > ed[t])
        {
            bufl[index] = cal0(index + 1, st[t], bufl, bufr);
            toend = bufl[index];

            toend += dist + place - ed[t];
        }
        // 其实直接只用这一部分也可以
        else
        {
            {
                if (bufl[index] == LLONG_MAX)
                    bufl[index] = cal0(index + 1, st[t], bufl, bufr);
                if (bufr[index] == LLONG_MAX)
                    bufr[index] = cal0(index + 1, ed[t], bufl, bufr);

                toend = min(bufl[index] + dist + (ed[t] - place), bufr[index] + dist + (place - st[t]));
            }
        }
    }
    // only one ball
    // 只有一个球的时候
    else
    {
        if (bufl[index] == LLONG_MAX)
        {
            bufl[index] = cal0(index + 1, st[t], bufl, bufr);
            bufr[index] = bufl[index];
        }
        toend = bufl[index] + abs(place - st[t]);
    }

    return toend;
}

// 删除了位置判定的修改版本 595 ms
ll cal1(int index, int place, vector<ll> &bufl, vector<ll> &bufr)
{
    if (index == colors.size())
    {
        return abs(place);
    }

    int t = colors[index];

    ll toend = 0;

    if (st[t] != ed[t])
    {
        ll dist = ed[t] - st[t];

        // 删除了 place 的位置判定
        if (bufl[index] == LLONG_MAX)
            bufl[index] = cal1(index + 1, st[t], bufl, bufr);
        if (bufr[index] == LLONG_MAX)
            bufr[index] = cal1(index + 1, ed[t], bufl, bufr);

        // 没有了位置判定的话这里需要加上 abs
        toend = min(bufl[index] + dist + abs(ed[t] - place), bufr[index] + dist + abs(place - st[t]));
    }
    // only one ball
    // 只有一个球的时候
    else
    {
        if (bufl[index] == LLONG_MAX)
        {
            bufl[index] = cal1(index + 1, st[t], bufl, bufr);
            bufr[index] = bufl[index];
        }
        toend = bufl[index] + abs(place - st[t]);
    }

    return toend;
}

// 再修改版本 连球的个数判定也删除了
// 652 ms
ll cal2(int index, int place, vector<ll> &bufl, vector<ll> &bufr)
{
    if (index == colors.size())
    {
        return abs(place);
    }

    int t = colors[index];

    ll toend = 0;

    // 连球的个数判定也删除
    ll dist = ed[t] - st[t];

    // 删除了 place 的位置判定
    if (bufl[index] == LLONG_MAX)
        bufl[index] = cal2(index + 1, st[t], bufl, bufr);
    if (bufr[index] == LLONG_MAX)
        bufr[index] = cal2(index + 1, ed[t], bufl, bufr);

    // 没有了位置判定的话这里需要加上 abs
    toend = min(bufl[index] + dist + abs(ed[t] - place), bufr[index] + dist + abs(place - st[t]));

    return toend;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    set<int> setcol;

    rep(0, i, n)
    {
        ll x, c;
        cin >> x >> c;
        if (st[c] == 0)
            st[c] = x;
        else
            st[c] = min(st[c], x);
        if (ed[c] == 0)
            ed[c] = x;
        else
            ed[c] = max(ed[c], x);
        setcol.insert(c);
    }
    for (auto i = setcol.begin(); i != setcol.end(); i++)
    {
        colors.push_back(*i);
    }
    vector<ll> bufl(colors.size(), LLONG_MAX);
    vector<ll> bufr(colors.size(), LLONG_MAX);

    cout << cal0(0, 0, bufl, bufr) << endl;
    return 0;
}
