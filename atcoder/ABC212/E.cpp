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


const ll mod=998244353;

ll add(ll a,ll b){
    return (a+b)%mod;
}
ll ms(ll a,ll b){
    while(b>a){
        b-=mod;
    }
    return (a-b)%mod;
}

int main(int argc, char const *argv[])
{
    ll n,m,k;
    cin>>n>>m>>k;

    vl2d dp(n+1,vl(k+1,0));
    vl2d dc(n+1);
    vl sum(k+1,0);

    dp[1][k]=1;
    sum[k]=1;

    repe(1,i,n){
        dc[i].pb(i);
    }
    rep(0,i,m){
        int u,v;
        cin>>u>>v;

        dc[u].pb(v);
        dc[v].pb(u);
    }

    for(int day=k-1;day>=0;day--){
        for(int city=1;city<=n;city++){

            ll fin=sum[day+1];

            for(ll dcc:dc[city]){
                fin=ms(fin,dp[dcc][day+1]);
            }

            dp[city][day]=fin;
            sum[day]=add(sum[day],fin);
        }
    }

    cout<<dp[1][0]<<endl;
    return 0;
}
