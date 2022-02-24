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


#define SOLVEA


int main(int argc, char const *argv[])
{
    int n,d;
    cin>>n>>d;
    vector<pii> wall(n);

    rep(0,i,n){
        cin>>wall[i].first>>wall[i].second;
    }

    int ans=0;

    #ifdef SOLVEA
    int x=INT_MAX;
    sort(wall.begin(),wall.end());

    for(int i=n-1;i>=0;i--){
        auto &[l,r]=wall[i];
        if(r<x)ans++,x=l-d+1;
    }

    #else

    int x=INT_MIN;
    sort(wall.begin(),wall.end(),[](pii &a,pii &b){return a.second<b.second;});

    for(auto& [l,r]:wall){
        if(x+d-1<l)ans++,x=r;
    }

    #endif
    cout<<ans<<endl;
    return 0;
}
