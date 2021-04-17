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
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()

unsigned long long cal(vector<pull> data,int p,unsigned long long sum,unsigned long long mut){
    if(p==data.size())return 0;
    if(sum==mut)return sum;
    if(sum<mut)return 0;

    unsigned long long bigres=0;
    if(sum%data[p].fr==0){
        vector<pull> buf;
        while(mut<sum&&data[p].sc>0){
            mut*=data[p].fr;
            sum-=data[p].fr;
            data[p].sc--;
            if(mut<sum)
                buf.push_back(mp(sum,mut));
        }
        if(mut==sum){
            return mut;
        }
        else{
            unsigned long long bigres=0;
            for(auto i=buf.rbegin();i!=buf.rend();i++){
                auto pa=*i;
                auto rec=cal(data,p+1,pa.fr,pa.sc);
                bigres=max(bigres,rec);
            }

        }
    }
    auto rec=cal(data,p+1,sum,mut);
    return max(bigres,rec);
}

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    rep(0,test,T){
        int m;
        cin>>m;
        vector<pull> data(m);
        unsigned long long sum=0;
        rep(0,i,m){
            cin>>data[i].fr>>data[i].sc;
            sum+=data[i].fr*data[i].sc;
        }
        
        unsigned long long res=cal(data,0,sum,1);

        cout<<"Case #"<<test+1<<": "<<res<<endl;
    }
    
    return 0;
}
