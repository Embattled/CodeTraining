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

int n,m;

int main(int argc, char const *argv[])
{
    cin>>n>>m;

    vector<int> res(n);
    ll ans=0;

    vector<bool> xorres(1<<m,false);
    for(int i=1;i<(1<<m);i++){
        xorres[i]=!xorres[i-(i&(-i))];
    }

    vi buf(n,0);
    int pairnum=0;
    rep(0,i,n){
        string s;
        cin>>s;
        res[i]=stoi(s,0,2);

        if(i>=1){
            if(xorres[res[i]^res[i-1]]){
                buf[i]=pairnum-buf[i-1];
            }
            else{
                buf[i]=buf[i-1];
            }
        }
        ans+=buf[i];
        pairnum++;
    }

    cout<<ans<<endl;




    
    return 0;
}
/*
1. 相同的字母一定得到相同的分  如果全都一样那么分数一定一样
2. 不同的回答分数会分给任意一方, 如果 不同的回答的个数是偶数, 那么存在分数相同的情况
3. 目标是求出两两之间不同回答的个数, 即异或后 1 的个数 是奇数的情况, 


somenum  sumnum



A^B^B^C = A^C

A^C

回答的组合最多是 2^20   1e6  

每个回答可以得到 1的个数和 0 的个数  

*/