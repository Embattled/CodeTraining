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
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<ull,ull> pull;
typedef vector<int> vi;
typedef vector<vector<int>> vi2d;
typedef vector<ll> vl;
typedef vector<vector<ll>> vl2d; 

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

int main(int argc, char const *argv[])
{
    ll h,w,c;
    cin>>h>>w>>c;
    vl2d sta(h,vl(w));

    rep(0,y,h){
        rep(0,x,w){
            cin>>sta[y][x];
        }
    }

    ll res=LLONG_MAX;
    // 很难用一个正向循环达成所有可能情况
    // 用简单的循环走正反两边即可
    vl2d dp1(sta);
    rep(0,y,h){
        rep(0,x,w){
            if(x-1>=0){
                dp1[y][x]=min(dp1[y][x],dp1[y][x-1]+c);
                res=min(res,dp1[y][x-1]+c+sta[y][x]);
            }
            if(y-1>=0){
                dp1[y][x]=min(dp1[y][x],dp1[y-1][x]+c);
                res=min(res,dp1[y-1][x]+c+sta[y][x]);
            }
        }
    }
    vl2d dp2(sta);
    rep(0,y,h){
        for(int x=w-1;x>=0;x--){
            if(x+1<w){
                dp2[y][x]=min(sta[y][x],dp2[y][x+1]+c);
                res=min(res,dp2[y][x+1]+c+sta[y][x]);
            }
            if(y-1>=0){
                dp2[y][x]=min(dp2[y][x],dp2[y-1][x]+c);
                res=min(res,dp2[y-1][x]+c+sta[y][x]);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
