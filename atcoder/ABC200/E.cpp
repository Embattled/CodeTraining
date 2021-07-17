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
    ll n,k;
    cin>>n>>k;

    k--;
    n--;

    ll sum=0;
    while(k>=((sum+1)*(sum+2)/2)){
        k-=((sum+1)*(sum+2)/2);
        sum++;
    }
    cout<<sum<< "-sum    k-"<<k<<endl;

    ll beauty=max(0ll,sum-2*n);
    while(k>= ((sum-beauty+1)-2*max(0ll,sum-beauty-n))&&beauty<n){
        k-=(sum-beauty+1)-2*max(0ll,sum-beauty-n);
        beauty++;
        // cout<<beauty<<" "<<(sum-beauty+1)-2*n<<endl;
    }
    // cout<<beauty<<endl;


    ll taste=max(0ll,sum-beauty-n);
    while(k>0){
        taste++;
        k--;
    }
    // cout<<taste<<endl;

    ll pop=sum-beauty-taste;
    cout<<beauty+1<<" "<<taste+1<<" "<<pop+1<<endl;
    
    return 0;
}
