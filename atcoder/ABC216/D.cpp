#include <stack>
#include <queue>
#include <set>
#include <array>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> cy(m);
    vector<int> ki(m),pi(m,0);

    queue<int> q;
    rep(0,i,m){
        q.push(i);
        cin>>ki[i];
        rep(0,j,ki[i]){
            int a;
            cin>>a;
            cy[i].push_back(a);
        }
    }

    vector<int> place(n+1,-1);
    int pn=0;
    while(!q.empty()){
        int cyi=q.front();
        q.pop();

        if(ki[cyi]==pi[cyi]){
            continue;
        }
        int col=cy[cyi][pi[cyi]];
        pi[cyi]++;

        if(place[col]==-1){
            place[col]=cyi;
        }
        else{
            q.push(cyi);
            q.push(place[col]);
            pn++;
        }
    }
    if(pn==n){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}
