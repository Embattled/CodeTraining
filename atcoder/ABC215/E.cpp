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

int mov[]={1,0,-1,0,1};
int h,w;


const ll mod=998244353;
bool check(int x,int y){
    if(x<0||x>=h||y<0||y>=w){
        return true;
    }
    return false;
}

int cov(char c){
    return c-'A';
}

int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin>>n>>s;

    vector<vl2d> dp(n,vl2d(1024,vl(11,0)));
    

    dp[0][1023][cov(s[0])]=1;
    dp[0][1023][10]=1;

    for(int i=1;i<n;i++){
        int nc=cov(s[i]);

        for(int lc=0;lc<11;lc++){
            for(int st=0;st<1024;st++){
                
                // 不选
                dp[i][st][lc]=(dp[i-1][st][lc]+dp[i][st][lc])%mod;

                // 可选
                int pnc=1<<nc;
                if(st&pnc){
                    // 相同或者空
                    if(nc==lc||lc==10){
                        dp[i][st][nc]=(dp[i][st][nc]+dp[i-1][st][lc])%mod;
                    }
                    // 不相同
                    else{
                        // 非空
                        dp[i][st^(1<<lc)][nc]=(dp[i][st^(1<<lc)][nc]+dp[i-1][st][lc])%mod;
                    }
                }
            }
        }
    }

    ll res=0;
    for(int st=0;st<1024;st++){
        for(int lc=0;lc<10;lc++){
            res=(res+dp[n-1][st][lc])%mod;
        }
    }
    cout<<res<<endl;;

    return 0;
}
