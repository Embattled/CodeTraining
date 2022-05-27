#include <stack>
#include <queue>
#include <set>
#include <array>
#include <vector>
#include <deque>
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
typedef vector<vector<int>> vi2d;
typedef vector<ll> vl;
typedef vector<vector<ll>> vl2d;
typedef vector<char> vc;
typedef vector<vector<char>> vc2d;

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

int mov[] = {1, 0, -1, 0, 1};
int h, w;

const ll mod = 998244353;
bool check(int x, int y)
{
    if (x < 0 || x >= h || y < 0 || y >= w)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vl a(n);
    rep(0,i,n){
        cin>>a[i];
    }
    ll maxv=1e15;
    vl2d dp1(n,vl(2,maxv));
    vl2d dp2(n,vl(2,maxv));

    dp1[0][0]=0;
    dp1[0][1]=maxv;
    
    dp2[0][0]=maxv;
    dp2[0][1]=a[0];

    rep(1,i,n){
        dp1[i][0]=dp1[i-1][1];
        dp1[i][1]=min(dp1[i-1][0],dp1[i-1][1])+a[i];

        dp2[i][0]=dp2[i-1][1];
        dp2[i][1]=min(dp2[i-1][0],dp2[i-1][1])+a[i];
    }
    cout<< min(dp1[n-1][1],min(dp2[n-1][0],dp2[n-1][1]))<<endl;;

    return 0;
}
