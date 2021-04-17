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

// n: number of totol elements +1
// nowi: now can change's
bool f(int n,int cost,int nowcost,int nowi,vector<int> &res){
    if(nowi==n&&nowcost==cost){
        return true;
    }
    int restcost=cost-nowcost;
    int restsearch=n-nowi;
    if(nowcost>=cost||nowi>=n||(restcost<restsearch)||(restcost>((nowi+n-1)*restsearch)/2)){
        return false;
    }

    for(int i=1;i<=nowi;i++){
        if(f(n,cost,nowcost+i,nowi+1,res)){
            res[nowi-2]=i;
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    rep(0,testcase,t){
        int n,cost;
        cin>>n>>cost;
        // n-1 values
        vi res(n-1);    

        if(f(n+1,cost,0,2,res)){
            vi outp(n);
            rep(0,i,n)outp[i]=i+1;

            rep(0,i,n-1){
                int s=n-2-i;
                reverse(outp.begin()+s,outp.begin()+s+res[i]);
            }
            cout<<"Case #"<<testcase+1<<": ";
            for(auto r:outp)cout<<r<<' ';
            cout<<endl;
        }
        else{
            cout<<"Case #"<<testcase+1<<": IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
