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
#define rep(s, i, n) for (ll(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (ll(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (ll(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (ll(i) = (s); (i) >= (n); (i)--)

int main(int argc, char const *argv[])
{
    ll N,Q;
    deque<ll> A;

    cin>>N>>Q;
    rep(0,query,Q){
        ll t;
        cin>>t;
        
        // N = rest shuffle time
        // i = now index
        // aim = shuffle aim place
        ll n=N-(t-1),i=t,aim=t-1;
        
        while(n>=i){
            n-=i;
            aim+=i;
            i=aim;
        }
        if(n>0){
            i-=n;
        }
        cout<<i<<endl;
        
    }


    return 0;
}
