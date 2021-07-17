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
    int n,q;
    cin>>n>>q;

    vector<vector<int>> road(n+1);
    rep(0,ro,n-1){
        int a,b;
        cin>>a>>b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    vector<bool> check(n+1,true);
    vector<bool> ident(n+1,false);

    queue<int> qu;
    qu.push(1);
    check[1]=false;
    while(!qu.empty()){
        int now=qu.front();
        qu.pop();

        for(int next:road[now]){
            if(check[next]){
                ident[next]=!ident[now];
                check[next]=false;
                qu.push(next);
            }
        }
    }

    rep(0,query,q){
        int c,d;
        cin>>c>>d;
        if(ident[c]==ident[d]){
            cout<<"Town"<<endl;
        }
        else{
            cout<<"Road"<<endl;
        }
    }

    return 0;
}
