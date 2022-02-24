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

vi res;
void dfs(vector<set<int>> &conn,int i,int fa){
    res.pb(i);
    for(int n:conn[i]){
        if(n==fa)continue;
        dfs(conn,n,i);
        res.pb(i);
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vector<set<int>> conn(n+1);

    rep(0,i,n-1){
        int a,b;
        cin>>a>>b;
        conn[a].insert(b);
        conn[b].insert(a);
    }
    dfs(conn,1,0);
    for(int i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
