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
    cin>>h>>w;

    vector<vector<char>> s(h,vector<char>(w));
    vi2d dp(h,vi(w,INT_MAX));

    rep(0,i,h){
        rep(0,j,w){
            cin>>s[i][j];
        }
    }

    dp[0][0]=0;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    q.push(mp(0,mp(0,0)));
    while(!q.empty()){
        auto [nowc,pos]=q.top();
        q.pop();

        auto [x,y]=pos;
        // old change
        if(dp[x][y]<nowc)continue;

        // 4-direction directly move
        for(int i=0;i<4;i++){
            int nx=x+mov[i];
            int ny=y+mov[i+1];
            if(check(nx,ny))continue;

            if(s[nx][ny]=='.'&&(nowc<dp[nx][ny])){
                dp[nx][ny]=nowc;
                q.push(mp(nowc,mp(nx,ny)));
            }

        }

        // 5X5 square move
        for(int ax=-2;ax<=2;ax++){
            for(int ay=-2;ay<=2;ay++){
                if(abs(ax)==2&&abs(ay)==2)continue;

                int nx=x+ax;
                int ny=y+ay;
                if(check(nx,ny))continue;

                if(nowc+1<dp[nx][ny]){
                    dp[nx][ny]=nowc+1;
                    q.push(mp(dp[nx][ny],mp(nx,ny)));
                }
            }
        }

    }

    cout<<dp[h-1][w-1]<<endl;
    return 0;
}
