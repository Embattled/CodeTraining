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

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    // origin order
    // 1-index
    vi A(n + 1);
    repe(1, i, n)
    {
        A[i] = i;
    }
    // 1-index
    vi line(m + 1);
    repe(1, i, m)
    {
        cin >> line[i];
        swap(A[line[i]], A[line[i] + 1]);
    }
    // 1-index
    vi B(n + 1);
    set<int> diffindex;
    repe(1, i, n)
    {
        cin >> B[i];
        // if this place is different, insert the index
        if (A[i] != B[i])
        {
            diffindex.insert(i);
        }
    }

    // answer
    int ansh = -1, ansk;

    // from h=m+1 to h=1
    rrepe(m + 1, h, 1)
    {
        // get the first and second different index
        int diffi1 = *(diffindex.begin());
        int diffi2 = *(++diffindex.begin());

        // check success condition
        if (diffindex.size() == 2 && (diffi2 - diffi1) == 1)
        {
            // save the answer and exit search
            ansh = h;
            ansk = diffi1;
            break;
        }

        // if failure, execute (h-1)th line's swap.
        // because no h=0's line, check if h>1
        if (h > 1)
        {
            // save index to make a clearly code.
            int k = line[h - 1];

            // execute h-1th line swap
            swap(A[k], A[k + 1]);
            swap(B[k], B[k + 1]);

            // get the new condition.
            if (A[k] == B[k])
            {
                diffindex.erase(k);
            }
            else
            {
                diffindex.insert(k);
            }
            if (A[k + 1] == B[k + 1])
            {
                diffindex.erase(k + 1);
            }
            else
            {
                diffindex.insert(k + 1);
            }
        }
    }
    if (ansh == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ansh << " " << ansk << endl;
    }

    return 0;
}
