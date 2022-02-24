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

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vl a(n),b(m);

    rep(0,i,n){
        cin>>a[i];
    }
    rep(0,i,m){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0;
    ll res=INT_MAX;

    while(i<n&&j<m){
        res=min(res,abs(a[i]-b[j]));
        if(a[i]>b[j]){
            j++;
        }
        else if(b[j]>a[i]){
            i++;
        }
        else{
            if(i==n-1){
                j++;
            }
            else if(j==m-1){
                i++;
            }
            else if(a[i+1]>b[j+1]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout<<res<<endl;
    
    return 0;
}
