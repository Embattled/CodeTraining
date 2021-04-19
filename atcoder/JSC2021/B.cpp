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

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    vi b(m);
    rep(0,i,n)cin>>a[i];
    rep(0,i,m)cin>>b[i];

    int i=0,j=0;
    vi ans;
    while(i<n&&j<m){
        if(a[i]!=b[j]){
            if(a[i]>b[j]){
                ans.pb(b[j++]);
            }
            else{
                ans.pb(a[i++]);
            }
        }
        else{
            i++;
            j++;
        }
    }
    while(i<n){
        ans.pb(a[i++]);
    }
    while(j<m){
        ans.pb(b[j++]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i==ans.size()-1)cout<<endl;
        else cout<<" ";
    }
    
    return 0;
}
