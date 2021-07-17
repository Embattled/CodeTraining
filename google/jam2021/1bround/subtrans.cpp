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

/* 
    解法相当简单, 几个循环就可以
    关键在于寻找初始金属的编号上界
    需要根据数学知识反推出来, 在极限的可解情况下, 最大需要402编号的金属一块即可满足要求

    对如输入的 a,b, 从m金属出发
        那么可能所有可能生成的金属编号Ki
        都有:
            g=gcb(a,b)
            Ki%g==m%g

*/
string solve() {
	int n,a,b;
    cin>>n>>a>>b;
    vi bneed(n+1);
    int bnneed=0;
    repe(1,i,n){
        cin>>bneed[i];
        bnneed+=bneed[i];
    }
    for(int s=1;s<403;s++){
        vi have(403,0);
        have[s]=1;
        int nhave=1;
        vi need(bneed);
        int nneed=bnneed;
        int split=s;

        while(nneed>0&&nhave>0){
            repe(1,i,n){
                if(have[i]>0&&need[i]>0){
                    int minus=min(have[i],need[i]);
                    have[i]-=minus;
                    need[i]-=minus;
                    nneed-=minus;
                    nhave-=minus;
                }
            }
            while(split>0&&have[split]<=0)split--;
            if(split>0){
                if(split-b>0){
                    have[split-b]+=have[split];
                    nhave+=have[split];
                }
                if(split-a>0){
                    have[split-a]+=have[split];
                    nhave+=have[split];
                }
                nhave-=have[split];
                have[split]=0;
            }
        }
        if(nneed==0){
            return to_string(s);
        }
    }
    return "IMPOSSIBLE";
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
