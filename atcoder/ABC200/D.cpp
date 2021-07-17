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

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    map<int,vector<int>> m;

    bool ok=false;
    vi B,C;

    rep(0,it,n){
        int a;
        cin>>a;
        a%=200;

        // if(ok)cout<<"it"<<it<<" ok"<<endl;
        // else{
        //     for(auto &i:m){
        //         cout<<i.first<<" "<<i.second.size()<<endl;
        //     }
        //     cout<<it+1<<" end"<<endl;
        // }
        if(ok)continue;

        for(auto &i:m){
            int mod=(a+i.first)%200;

            // get result
            if(m.find(mod)!=m.end()){
                ok=true;
                for(auto &j:m[mod]){
                    B.push_back(j);
                }
                for(auto &j:i.second){
                    C.push_back(j);
                }
                C.push_back(it+1);
                break;
            }
        }

        if(ok)continue;


        map<int,vector<int>> copym(m);
        // add new thing
        for(auto &i:copym){
            int mod=(a+i.first)%200;
            for(auto &j:i.second){
                m[mod].push_back(j);
            }
            m[mod].push_back(it+1); 
        }

        if(ok)continue;
        if(m.find(a)!=m.end()){
            ok=true;
            for(auto &j:m[a]){
                B.push_back(j);
            }
            C.push_back(it+1);
        }
        else
            m[a].push_back(it+1);

    }
    
    if(ok){
        cout<<"Yes"<<endl;
        cout<<B.size();
        rep(0,i,B.size()){
            cout<<" "<<B[i];
        }
        cout<<endl;
        cout<<C.size();
        rep(0,i,C.size()){
            cout<<" "<<C[i];
        }
        cout<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
