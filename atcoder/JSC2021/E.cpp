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

int geta(vector<int> &father,int i){
    if(father[father[i]]!=father[i]){
        father[i]=geta(father,father[i]);
    }
    return father[i];
}

int main(int argc, char const *argv[])
{
    string noans="impossible";
    int k;
    string s;
    cin>>k>>s;

    if(k==0){
        cout<<0<<endl;
        return 0;
    }
    int n=s.length();

    vi father(n);
    rep(0,i,n)father[i]=i;

    int len=n;
    while(len>0&&k>0){
        int sub=len>>1;
        for(int i=0;i<sub;i++){
            father[len-1-i]=i;
        }
        len=sub;
        k--;
    }
    if(k>0){
        cout<<noans<<endl;
        return 0;
    }

    map<int,vector<int>> type;
    rep(0,i,n){
        type[geta(father,i)].pb(i);
    }

    int res=0;
    for(auto &tp:type){
        int num=tp.second.size();
        map<char,int> ct;
        for(int i:tp.second){
            ct[s[i]]++;
        }
        int maxn=0;
        for(auto &cp:ct){
            maxn=max(maxn,cp.second);
        }
        res+=num-maxn;
    }

    cout<<res<<endl;
    return 0;
}
