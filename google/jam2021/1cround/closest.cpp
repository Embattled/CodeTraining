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

string solve() {
    double res=0;

    int n,K;
    cin>>n>>K;
    double k=K;
    set<int> data;
    rep(0,i,n){
        int c;
        cin>>c;
        data.insert(c);
    }

    double usetwo=0;
    priority_queue<double> useone;

    auto i=data.begin();
    useone.push((*i-1)/k);
    int old=*i;
    i++;
    while(i!=data.end()){
        usetwo=max(usetwo,(*i-old-1)/k);
        useone.push(((*i-old)/2)/k);
        old=*i;
        i++;
    }
    useone.push((k-old)/k);
    double a=useone.top();
    useone.pop();
    a=useone.top()+a;

    res=max(usetwo,a);
    return to_string(res);
}



int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    rep(0,test,T){
        auto res=solve();
        cout<<"Case #"<<test+1<<": "<<res<<endl;
    }
    return 0;
}
