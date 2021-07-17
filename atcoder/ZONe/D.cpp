#include <stack>
#include <queue>
#include <set>
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
    string s;
    cin>>s;

    deque<char> T;
    int r=0;

    rep(0,i,s.length()){
        if(s[i]=='R'){
            r=1-r;
        }
        else{
            if(r){
                if(!T.empty()&&T.front()==s[i]){
                    T.pop_front();
                }
                else{
                    T.push_front(s[i]);
                }
            }
            else{
                if(!T.empty()&&T.back()==s[i]){
                    T.pop_back();
                }
                else{
                    T.push_back(s[i]);
                }
            }
        }
    }

    if(r){
        for(auto i=T.rbegin();i!=T.rend();i++){
            cout<<*i;
        }
        cout<<endl;
    }
    else{
        for(auto i=T.begin();i!=T.end();i++){
            cout<<*i;
        }
        cout<<endl;
    }
    
    return 0;
}
