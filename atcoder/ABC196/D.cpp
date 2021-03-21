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
int ans=0;
int h,w,a,b;

void cal(int x,int y,vector<vector<bool>> s,int a){
    if(a==0){
        ans++;
        return;
    }
    if(x>=h){
        return;
    }
    if(y>=w){
        cal(x+1,0,s,a);
        return;
    }


    // yoko
    if(y<w&&y+1<w&&s[x][y]&&s[x][y+1]){
        auto news=s;
        news[x][y]=false;
        news[x][y+1]=false;
        cal(x,y+1,news,a-1);
    }

    // tate
    if(x<h&&x+1<h&&s[x][y]&&s[x+1][y]){
        auto news=s;
        news[x][y]=false;
        news[x+1][y]=false;
        cal(x,y+1,news,a-1);
    }

    // blank
    cal(x,y+1,s,a);
}

int main(int argc, char const *argv[])
{
    cin>>h>>w>>a>>b;
    vector<vector<bool>> s(h,vector<bool>(w,true));

    cal(0,0,s,a);

    cout<<ans<<endl;
    return 0;
}
