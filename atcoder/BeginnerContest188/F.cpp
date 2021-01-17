#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])


typedef long long int64;
typedef pair<int64, int64> ii;
map<ii, int64> cache;

template <typename T>
static constexpr T inf = numeric_limits<T>::max() / 2;

int64 solve(int64 y, int64 x)
{
    // trace(y, x);
    ii cur = {y, x};
    auto it = cache.find(cur);
    if (it != cache.end())
        return it->second;
    int64 ret = inf<int64>;
    if (y <= x)
    {
        return cache[cur] = x - y;
    }
    if (y % 2 == 0)
    {
        ret = min(ret, y - x);
        ret = min(ret, 1 + solve(y / 2, x));
    }
    else
    {
        ret = min(ret, 1 + solve(y + 1, x));
        ret = min(ret, 1 + solve(y - 1, x));
    }
    // trace(cur, ret);
    return cache[cur] = ret;
}

int main()
{
    int64 x, y;
    cin >> x >> y;
    int64 ret = solve(y, x);
    cout << ret << '\n';
    return 0;
}
