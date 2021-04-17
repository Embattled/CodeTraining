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


int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    rep(0,testcase,t){
        int x,y,res;
        cin>>x>>y;
        string s;
        cin>>s;

        int n=s.length();
        vector<vector<int>> buf(n,vector<int>(2,1e9));
        buf[0][0]=0;
        buf[0][1]=0;
        rep(1,i,n){
            if(s[i]=='C'){
                if(s[i-1]=='J'){
                    buf[i][0]=buf[i-1][1]+y;
                }
                else if(s[i-1]=='C'){
                    buf[i][0]=buf[i-1][0];
                }
                else {
                    buf[i][0]=min(buf[i-1][0],buf[i-1][1]+y);
                }
            }
            else if(s[i]=='J'){
                if(s[i-1]=='C'){
                    buf[i][1]=buf[i-1][0]+x;
                }
                else if(s[i-1]=='J'){
                    buf[i][1]=buf[i-1][1];
                }
                else {
                    buf[i][1]=min(buf[i-1][1],buf[i-1][0]+x);
                }
            }
            else{
                if(s[i-1]=='C'){
                    buf[i][1]=buf[i-1][0]+x;
                    buf[i][0]=buf[i-1][0];
                }
                else if(s[i-1]=='J'){
                    buf[i][1]=buf[i-1][1];
                    buf[i][0]=buf[i-1][1]+y;
                }
                else {
                    buf[i][0]=min(buf[i-1][1]+y,buf[i-1][0]);
                    buf[i][1]=min(buf[i-1][0]+x,buf[i-1][1]);
                }
            }
            // cout<<"i: "<<i<<" b[0]:"<<buf[i][0]<<" b[1]"<<buf[i][1]<<endl;
        }

        cout<<"Case #"<<testcase+1<<": "<<min(buf[n-1][0],buf[n-1][1])<<endl;
    }
    return 0;
}
