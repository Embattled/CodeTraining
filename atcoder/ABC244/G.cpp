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


int getPath(const vi2d& edge,const string &s, vector<bool> &check,int index,vi &ans){
    check[index]=false;
    int num=0;

    for(auto next:edge[index]){
        if(!check[next])continue;
        ans.pb(index);
        num++;
        int nn=getPath(edge,s,check,next,ans);
        if((nn&1)!=(s[next]-'0')){
            ans.pb(index);
            ans.pb(next);
            num++;
        }
    }
    ans.pb(index);
    num++;

    return num;
}

int main(int argc, char const *argv[])
{
    int n,m;
    string s;
    cin>>n>>m;

    vi2d edge(n);
    vector<bool> check(n,true);
    rep(0,i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        edge[v].pb(u);
        edge[u].pb(v);
    }
    cin>>s;

    vi ans;
    int n0=getPath(edge,s,check,0,ans);
    if((n0&1)!=(s[0]-'0')){
        ans.pb(edge[0][0]);
        ans.pb(0);
        ans.pb(edge[0][0]);
    }
    cout<<ans.size()<<endl;
    for(auto a:ans){
        cout<<a+1<<" ";
    }
    cout<<endl;
    return 0;
}
