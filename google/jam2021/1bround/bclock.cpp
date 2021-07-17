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

ll nano=1000000000;

ll tt=12*3600*nano;

string solve(ll *a) {
    for(int h=0;h<3;h++){
        for(int m=0;m<3;m++){
            if(m==h)continue;
            int s=3-h-m;

            // dif ticks 求出分针和时针的差
            ll difhm=a[m]-a[h];

            // 一个时分差有12个小时的可能
            for(int hour=0;hour<12;hour++){
                // 注意这里的 hour 并不代表最后计算出来的时间就是 hour 时 多少多少分
                // 只是用来遍历所有的基础tick差


                // 小时0分时分基础tick差
                // 时针比分针超前了 sdif 个 tick
                ll sdif=hour*3600*nano;

                // 当前的分针时针tick差加上基础的tick差
                // 得到了该小时开始后的 tick 更改量
                ll puredif=(sdif+difhm+tt)%tt;

                // 一nano 秒, 分针会追上时针11个 ticks
                // 得到该小时候开始后的 nano 秒
                ll sec=puredif/11;

                // 分针的正确 tick 应该是 sdif+sec
                // 计算得到 cals 修正量
                ll cals=(sec+sdif-a[h]+tt)%tt;
                
                // 修正
                ll revh=(cals+a[h]+tt)%tt;
                ll revm=(cals+a[m]+tt)%tt;
                ll revs=(cals+a[s]+tt)%tt;

                if((revm%12!=0)||(revs%720!=0))continue;

                // 如果 秒针 符合则是正确结果
                // 根据 sec 或者 时针分针都可以用来计算秒针的正确位置
                // 因为运行时间已经知道了
                if(revs==60*(revm%(12*60*nano))){
                    // cout<<difhm<<endl;
                    // cout<<puredif<<endl;


                    // hour 并不代表最后计算出来的时间就是 hour 时 多少多少分
                    // 需要重新计算计算求余后的小时
                    ll realhour=revh/(3600*nano);


                    // 计算 nano 秒
                    ll nanos=revh%(1000000000);

                    // 计算分钟
                    ll minute=revm/(12*60*nano);

                    // 计算秒
                    ll second=revs/(720*nano);
                    
                    return to_string(realhour)+" "+to_string(minute)+" "+to_string(second)+" "+to_string(nanos);
                }
            }
        }
    }
    return " ";
}
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    rep(0,test,T){
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];

        cout<<"Case #"<<test+1<<": "<<solve(a)<<endl;
    }
    return 0;
}
