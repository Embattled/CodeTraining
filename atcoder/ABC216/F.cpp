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

int lowbit(int num){
    return num&(-num);
}
void insert(vector<int> &v,int num,ll k){
    while(num){
        v[num]+=k;
        num-=lowbit(num);

    }
}
ll getsum(vector<int> &v,int num){
    ll sum=0;
    while(num){
        sum+=v[num];
        num-=lowbit(num);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<pii> A(n);
    vector<int> B(n);
    rep(0,i,n){
        cin>>A[i].fr;
        A[i].sc=i;
    }
    rep(0,i,n){
        cin>>B[i];
    }
    sort(A.begin(),A.end());
    ll res=0;


    
    rep(0,i,n){
        auto [mx,bi]=A[i];

        auto rest=mt.upper_bound(mx-bi);
        res=(res)



    }



    cout<<res<<endl;
    return 0;
}
