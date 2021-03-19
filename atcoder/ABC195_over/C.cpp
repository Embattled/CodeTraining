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

int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    string ns=to_string(n);

    vi nmcoma(17);
    for(int i=1,coma=0;i<17;i++){
        nmcoma[i]=coma;
        if(i%3==0){
            coma++;
        }
    }

    ll res=0;
    ll nn=1;
    int nsl=ns.length();
    for(int i=0;i<nsl-1;i++){
        res+=(ns[nsl-1-i]-'0')*nmcoma[nsl]*nn;
        res+=nmcoma[i+1]*nn*9;
        nn*=10;
    }
    res+=(ns[0]-'0'-1)*nmcoma[nsl]*nn;
    res+=nmcoma[nsl];
    cout<<res<<endl;


    
    return 0;
}
