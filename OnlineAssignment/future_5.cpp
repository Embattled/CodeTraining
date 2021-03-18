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


const ll mod=100003;
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    
    map<int,int> cn;

    ll compose=1;
    repe(1,i,n){
        int c;
        cin>>c;
        cn[c]++;
        compose=(compose*cn[c])%mod;
    }
    ll type=cn.size();
    ll order=1;

    // wrong method, should consider situation like:
    // 1112  1121 1211 2111
    // repe(2,num,type){
    //     order=(order<<1)%mod;
    // }

    auto index=++cn.rbegin();
    while(index!=cn.rend()){
        order=(order*(index->second+1)%mod);
        index++;
    }

    cout<<(order*compose)%mod<<endl;
    return 0;
}
