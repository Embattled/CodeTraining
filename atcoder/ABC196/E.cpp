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
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
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

map<int,pair<bool,ll>> data;
int n;


// nowv = now range lowest  value
void cal(int i,int start,ll nowv,ll addv,vl &a,vl &t,bool sv){
    if(i==n){
        if(sv)
            data[start]=mp(sv,nowv+addv);
        else
            data[start]=mp(sv,addv);
    }

    if(t[i]==1){
        addv+=a[i];
        cal(i+1,start,nowv,addv,a,t,false||sv);
    }
    else if(t[i]==2){
        if(nowv+addv>=a[i]){
            cal(i+1,start,nowv,addv,a,t,sv||false);
        }
        else{
            cal(i+1,start,a[i],0,a,t,true);

            cal(i+1,start+(a[i]-(nowv+addv)),a[i]-addv,addv,a,t);
        }
    }
    else{
        if(nowv+addv>=a[i]){
            cal(i+1,start,a[i],0,a,t);
        }
        else{
            cal(i+1,start,nowv,addv,a,t);

            cal(i+1,start+(a[i]-(nowv+addv)),a[i],0,a,t);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    vl a(n);
    vl t(n);
    rep(0,i,n){
        cin>>a[i]>>t[i];
    }

    cal(0,-1e9,-1e9,0,a,t,false);

    int q;
    cin>>q;
    vl x(n);
    rep(0,i,q){
        cin>>x[i];


        ll ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
