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

struct d{
    array<bool,32> d{false};
};
int bit[]={1,2,4,8,16};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    map<int,d> data;
    rep(0,i,n){
        int one[5];
        rep(0,j,5){
            cin>>one[j];
        }
        rep(0,j,5){
            int b=0;
            rep(0,k,5){
                if(one[k]>=one[j]){
                    b|=bit[k];
                }
            }
            data[one[j]].d[b]=true;
        }
    }

    array<bool,32> now{false};
    for(auto i=data.rbegin();i!=data.rend();i++){
        rep(0,k,32){
            now[k]=now[k]||i->second.d[k];
        }

        for(int p1=1;p1<32;p1++){
            if(!now[p1])continue;
            if(p1==31){
                cout<<i->first<<endl;
                return 0;
            }
            for(int p2=p1+1;p2<32;p2++){
                if(!now[p2])continue;
                if((p1|p2)==31){
                    cout<<i->first<<endl;
                    return 0;
                }
                for(int p3=p2+1;p3<32;p3++){
                    if(!now[p3])continue;
                    if((p1|p2|p3)==31){
                        cout<<i->first<<endl;
                        return 0;
                    }
                }
            }
        }

    }
    
    return 0;
}
