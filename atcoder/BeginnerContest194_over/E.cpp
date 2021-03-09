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

int main(int argc, char const *argv[])
{
    int x, y, a, b, n, m, k, j;
    cin >> n >> m;

    vi arr(n);
    vi buf(n, 0);
    set<int> s;
    // 先代表所有的数都缺少
    for (int i = 0; i <= n; i++)
    {
        s.insert(i);
    }
    // 0开始的n个数, 即代表可能的 mex最大值为 n
    int res = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 外部索引
    int i = 0;
    for (; i < m; i++)
    {
        buf[arr[i]]++;
        // 这里可以直接删除
        s.erase(arr[i]);
    }
    // 直接访问 set.begin 就可以得到当前的 mex
    res = min(res, *s.begin());
    // 开始区间移动
    for (; i < n; i++)
    {
        if (arr[i] == arr[i - m])
        {
            res = min(res, *s.begin());
            continue;
        }

        s.erase(arr[i]);
        buf[arr[i]]++;

        buf[arr[i - m]]--;
        if (buf[arr[i - m]] == 0)
        {
            s.insert(arr[i - m]);
        }
        res = min(res, *s.begin());
    }
    cout << res << endl;
    return 0;
}
