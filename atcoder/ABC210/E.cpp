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

int gcd(int a,int b){

    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;

    // sieve of eratosthenes
    vector<pii> c(m);
    rep(0,i,m){
        cin>>c[i].sc>>c[i].fr;
    }
    ll cost=0;
    sort(c.begin(),c.end());

    for(auto [i,a]:c){
        int old=n;
        n=gcd(n,a);
        cost+=i*(ll)(old-n);

        if(n==1){
            break;
        }
    }
    if(n!=1){
        cout<<-1<<endl;
    }
    else{
        cout<<cost<<endl;
    }
    return 0;
}
