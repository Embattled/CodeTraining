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

ll mod=1e9+7;
int main(int argc, char const *argv[])
{
    ll n,m;
    cin>>n>>m;

    vl2d conn(n+1);
    rep(0,i,m){
        ll a,b;
        cin>>a>>b;

        conn[a].pb(b);
        conn[b].pb(a);
    }

    vector<pll> dis(n+1,mp(LLONG_MAX,0));
    dis[1]=mp(0,1);

    queue<ll> q;
    q.push(1);
    
    while(!q.empty()){
        auto now=q.front();
        q.pop();

        ll c=dis[now].fr+1;

        for(auto next:conn[now]){
            if(c<dis[next].fr){
                dis[next].fr=c;
                dis[next].sc=dis[now].sc;
                q.push(next);
            }
            else if(c==dis[next].fr){
                dis[next].sc=(dis[next].sc+dis[now].sc)%mod;
                
            }
        }
    }
    cout<<dis[n].sc<<endl;
    return 0;
}
