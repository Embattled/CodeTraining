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
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
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

ll res = 0;
int n,K;

set<string> visited();
int mov[] = {1, 0, -1, 0, 1};

int cal(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n){
        return x*n+y;
    }
    return -1;
}

void dfs(string m,int k,int x,int y,set<pii> cnn){
    visited.insert(m);
    m[cal(x,y)]='0';

    // not select
    

    // select
}

int main(int argc, char const *argv[])
{
    cin >> n >> K;

    string s;
    rep(0, i, n)
    {
        rep(0, j, n)
        {
            char c;
            cin >> c;
            if (c == '#'){
                s.pb('0')
            }
            else{
                s.pb('1');
            }
        }
    }

    vector<pii> start;
    vi2d check(n, vi(n, 1));
    rep(0, i, n)
    {
        rep(0, j, n)
        {
            if (check[i][j]&&s[cal(i,j)]==1)
            {
                check[i][j] = 0;
                start.pb(mp(i, j));

                queue<pii> q;
                q.push(mp(i, j));
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    rep(0, i, 4)
                    {
                        int nx = x + mov[i];
                        int ny = y + mov[i + 1];
                        if (cal(i,j)==-1 || check[nx][ny] != 1)
                        {
                            continue;
                        }
                        q.push(mp(nx,ny));
                        check[nx][ny]=0;
                    }
                }
            }
        }
    }
    for(auto [x,y]:start){
        dfs(s,K,x,y,set<pii>());
    }
    cout << res << endl;
    return 0;
}
