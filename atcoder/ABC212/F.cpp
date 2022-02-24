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

int main(int argc, char const *argv[])
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<map<int,pii>> p(n+1);
    vector<map<int,pii>> fin(n+1);

    rep(0,i,m){
        int a,b,s,t;
        cin>>a>>b>>s>>t;

        p[a][s]=mp(b,t);

    }
    rep(0,query,q){
        int x,y,z;
        cin>>x>>y>>z;

        int finish=y;
        string res;


        do{
            auto now=p[y].lower_bound(x);
            if(now!=p[y].end()){
                int start=now->fr;
                auto arrv=now->sc;

                if(start>=z){
                    res=to_string(y);
                    finish=start;
                }
                else if(arrv.sc>=z){
                    res=to_string(y)+" "+to_string(arrv.fr);
                    finish=arrv.sc;
                }
                else{
                    finish=arrv.sc;
                    x=arrv.sc;
                    y=arrv.fr;

                }
            }
            else{
                res=to_string(y);
                finish=z;
            }

        }while(finish<z);

        cout<<res<<endl;

    }
    
    return 0;
}
