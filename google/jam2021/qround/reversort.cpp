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
        int n;
        cin>>n;
        vi l(n+1);

        int res=0;
        repe(1,i,n){
            cin>>l[i];
        }

        repe(1,i,n-1){
            int jp;
            repe(i,j,n){
                if(l[j]==i){
                    jp=j+1;
                    break;
                }
            }

            res+=jp-i;
            reverse(l.begin()+i,l.begin()+jp);

        }
        cout<<"Case #"<<testcase+1<<": "<<res<<endl;
    }
    return 0;
}
