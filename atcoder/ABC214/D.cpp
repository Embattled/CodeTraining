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

bool check(int x,int y){
    if(x<0||x>=h||y<0||y>=w){
        return true;
    }
    return false;
}


void change(vl &s,vi &label,vi2d &ed,int i,int u,int v){
    
    int oldlabel=label[v];

    label[v]=i;
    s[i]++;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto next:ed[now]){
            if(next==u||label[next]!=oldlabel)continue;
            s[i]++;
            q.push(next);
            label[next]=i;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    ll res=0;

    vector<pair<ll,pii>> w;
    vi2d ed(n+1);

    vi label(n+1,0);
    vl s(n+1,0);
    s[0]=n;
    rep(0,i,n-1){
        int u,v;
        ll wi;
        cin>>u>>v>>wi;
        ed[u].pb(v);
        ed[v].pb(u);
        w.pb(mp(wi,mp(u,v)));
    }
    sort(w.begin(),w.end());
    for(int i=0;i<n-1;i++){
        auto [wi,edge]=w[n-2-i];
        auto [u,v]=edge;

        change(s,label,ed,i+1,u,v);
        s[label[u]]-=s[label[v]];
        res+=wi*(s[label[u]]*s[label[v]]);
    }
    cout<<res<<endl;
    
    return 0;
}
