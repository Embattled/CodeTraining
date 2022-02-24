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

bool check(int x,int y){
    if(x<0||x>=h||y<0||y>=w){
        return true;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vl s(n),t(n),res(n);
    rep(0,i,n){
        cin>>s[i];
    }
    rep(0,i,n){
        cin>>t[i];
    }
    res[0]=t[0];
    rep(1,i,n){
        res[i]=min(res[i-1]+s[i-1],t[i]);
    }
    if(res[0]>(res[n-1]+s[n-1])){
        res[0]=res[n-1]+s[n-1];
        rep(1,i,n){
            res[i]=min(res[i-1]+s[i-1],t[i]);
        }   
    }
    rep(0,i,n){
        cout<<res[i]<<endl;
    }

    return 0;
}
