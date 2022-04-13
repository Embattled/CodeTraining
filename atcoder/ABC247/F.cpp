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

int father(vi &l, int i){
    int fa=l[i];
    if(l[fa]!=fa){
        fa=father(l,fa);
        l[i]=fa;
    }
    return fa;
}

int main(int argc, char const *argv[])
{
    vl gx(200001),fx(200001);
    gx[0]=2;
    gx[1]=3;
    repe(2,i,200000){
        gx[i]=(gx[i-1]+gx[i-2])%mod;
    }

    fx[1]=1;
    fx[2]=3;
    fx[3]=4;
    repe(4,i,200000){
        fx[i]=(gx[i-2]+gx[i-4])%mod;
    }

    int n;
    string s;
    cin>>n;

    vi cn(n+1,0), fl(n+1,0), gp(n+1);
    repe(1,i,n){
        gp[i]=i;
    }

    vi Q(n),P(n);
    rep(0,i,n){
        cin>>P[i];
    }
    rep(0,i,n){
        cin>>Q[i];
    }

    rep(0,i,n){
        int p=P[i],q=Q[i];

        auto pi=fl[p];
        auto qi=fl[q];

        if(pi==0&&qi==0){
            fl[p]=i+1;
            fl[q]=i+1;
        }
        else if(pi!=0&&qi!=0){
            gp[qi]=father(gp,pi);
        }
        else if(pi==0){
            fl[p]=father(gp,qi);
        }
        else{
            fl[q]=father(gp,pi);
        }
    }
    ll ans=1;

    repe(1,i,n){
        int fi=father(gp,fl[i]);
        // cout<<"fi"<<fi<<endl;
        cn[fi]++;
    }
    repe(1,i,n){
        if(cn[i]!=0){
            // cout<<cn[i]<<endl;
            ans=(ans*fx[cn[i]])%mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}
