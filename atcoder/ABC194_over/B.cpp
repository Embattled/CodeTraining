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

    cin >> n;

    int res = INT_MAX;
    int minA = 100000;
    int minB = 100000;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        res = min(res, a + b);

        res = min(res, max(minB, a));
        res = min(res, max(minA, b));

        minA = min(minA, a);
        minB = min(minB, b);
    }

    cout << res << endl;
    return 0;
}
