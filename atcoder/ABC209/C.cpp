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
typedef vector<ll> vl;
 
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

const ll mod=1e9+7;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    ll res=0;
    vector<ll> c(n);

    rep(0,i,n){
        cin>>c[i];
    }
    sort(c.begin(),c.end());

    res=1;
    
    ll old=-1;
    ll mlt=0;

    for(int i=0,num=1;i<n;i++,num++){
        if(c[i]<num){
            cout<<0<<endl;
            return 0;
        }

        mlt+=((c[i]-old)-1)%mod;
        // show(mlt);
        res=(res*mlt)%mod;
        // show(res);
        old=c[i];
    }
    cout<<res<<endl;
    return 0;
}
