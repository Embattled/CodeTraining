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
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()
string noans = "UNSOLVABLE";
string s[3];
map<char, int> ans;

bool cal(int index, int si, vi digitu, map<char, int> letters, int carry)
{
    if (si == 2)
    {
        int is0 = s[0].length() - 1 - index;
        int is1 = s[1].length() - 1 - index;
        int is2 = s[2].length() - 1 - index;

        int d0 = is0 >= 0 ? letters[s[0][is0]] : 0;
        int d1 = is1 >= 0 ? letters[s[1][is1]] : 0;

        int sum = d0 + d1 + carry;
        int res = sum % 10;
        carry = sum / 10;

        char cs2 = s[2][is2];
        if (letters[cs2] == res || letters[cs2] == -1 && digitu[res] == 0)
        {
            digitu[res] = 1;
            letters[cs2] = res;
            return cal(index + 1, 0, digitu, letters, carry);
        }
        else
        {
            return false;
        }
    }

    if (index == s[2].length())
    {
        if (carry == 0&&letters[s[2][0]]!=0)
        {
            ans = letters;
            return true;
        }
        else
        {
            return false;
        }
    }

    int i = s[si].length() - 1 - index;
    // 有字母 且该字母还未搜索
    if (i >= 0 && letters[s[si][i]] == -1)
    {
        char c = s[si][i];

        map<char, int> np = letters;
        for (int dig = 0; dig < 10; dig++)
        {
            if (dig == 0 && i == 0 || digitu[dig])
                continue;
            np[c] = dig;
            vi nu = digitu;
            nu[dig] = 1;

            bool res = cal(index, si + 1, nu, np, carry);
            if (res)
                return true;
        }
        return false;
    }
    else
    {
        return cal(index, si + 1, digitu, letters, carry);
    }
}

int main(int argc, char const *argv[])
{

    cin >> s[0] >> s[1] >> s[2];

    map<char, int> letters;

    for (char c : s[0])
        letters[c] = -1;
    for (char c : s[1])
        letters[c] = -1;
    for (char c : s[2])
        letters[c] = -1;

    if (letters.size() > 10||s[2].length()<s[0].length()||s[2].length()<s[1].length())
    {
        cout << noans << endl;
        return 0;
    }
    vi digitu(10, 0);
    if (cal(0, 0, digitu, letters, 0))
    {
        for (int i = 0; i < 3; i++)
        {
            for (char c : s[i])
                cout << ans[c];
            cout << endl;
        }
    }
    else
    {
        cout << noans << endl;
    }

    return 0;
}
