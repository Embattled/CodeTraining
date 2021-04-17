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
    int res=1;
    int h,w,X,Y;
    cin>>h>>w>>X>>Y;

    X--;
    Y--;
    vector<vector<char>> sq(h,vector<char>(w));
    rep(0,i,h){
        rep(0,j,w){
            cin>>sq[i][j];
        }
    }
    int x,y;
    x=X,y=Y;
    while(++x<h&&sq[x][y]!='#')res++;

    x=X,y=Y;
    while(--x>=0&&sq[x][y]!='#')res++;

    x=X,y=Y;
    while(--y>=0&&sq[x][y]!='#')res++;

    x=X,y=Y;
    while(++y<w&&sq[x][y]!='#')res++;
    cout<<res<<endl;
    
    return 0;
}
