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
typedef vector<char> vc;
typedef vector<vector<char>> vc2d;

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

int mov[]={1,0,-1,0,1};
int h,w;

const ll mod=998244353;
bool check(int x,int y){
    if(x<0||x>=h||y<0||y>=w){
        return true;
    }
    return false;
}



int main(int argc, char const *argv[])
{
    int n;
    ll k;
    cin>>n>>k;

    vector<ll> fun(n+1,0);

    ll theorytime=0;
    ll theorysum=0;
    repe(1,i,n){
        cin>>fun[i];
        theorytime+=fun[i];
        theorysum+=((fun[i]+1)*(fun[i]))/2;
    }

    if(theorytime<=k){
        cout<<theorysum<<endl;
        return 0;
    }

    sort(fun.begin(),fun.end());
    ll i=n-1,now=fun[n];
    ll sum=0;
    while(k){
        ll dif=now-fun[i];
        ll num=n-i;
        i--;

        if(dif==0)continue;

        ll timecost=dif*num;
        if(k>=timecost){
            sum+= (timecost*(now+now-dif+1))/2;
            k-=timecost;
            now-=dif;
        }
        else{
            dif=k/num;
            ll res=k%num;
            sum+= (num*dif*(now+now-dif+1))/2;
            sum+= res*(now-dif);
            k=0;
        }
    }
    cout<<sum<<endl;




    return 0;
}
