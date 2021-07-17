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


bool check(ll n){
    string sn=to_string(n);

    for(int bit=1;bit<sn.length()-1;bit++){
        int i=0;
        int start=stoi(sn.substr(0,bit));

        while(i<sn.length()){
            string now=to_string(start);
            string nsn=sn.substr(i,now.length());
            if(nsn!=now){
                break;
            }
            i+=now.length();
            start++;
        }
        if(i==sn.length())return true;
    }
    return false;
}

string solve() {
    
	ll years;
    cin>>years;
    string sy=to_string(years);
    string res=sy+to_string(years+1);

    for(ll n=years+1;n<=1e6;n++){
        if(check(n)){
            return to_string(n);
        }
    }


    // for(int b=1;b<sy.length()-1;b++){
    //     string news;
    //     ll start=stoll(sy.substr(0,b));


    //     // while(start<(ll)pow(10,b)){
    //     //     news=to_string(start);
    //     //     ll next=start+1;
    //     //     while(news.length()<sy.length()){
    //     //         news+=to_string(next);
    //     //         next++;
    //     //     }
    //     //     if(news.length()<res.length()||(news.length()==res.length()&&news<res))            
    //     //     start++;
    //     // }

    //     if((int)pow(10,b)-start<(sy.length()/b)){

    //     }

    //     do{
    //         news=to_string(start);
    //         ll next=start+1;
    //         while(news.length()<sy.length()){
    //             news+=to_string(next);
    //             next++;
    //         }
    //         start++;
    //     }while(news.length()==sy.length()&&news<=sy);

    //     show(news);
    //     if(news.length()<res.length()||(news.length()==res.length()&&news<res))
    //         res=news;
    //     // res=min(res,news);
    // }

    return res;
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
