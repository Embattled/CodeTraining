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
typedef pair<ull,ull> pull;
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


bool trySolve(ll prod, ll sum,vector<pll> &a) {
    int m=a.size();
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		while(prod % a[i].first == 0) {
			prod /= a[i].first;
			sum -= a[i].first;
			cnt++;
		}
		if (cnt > a[i].second) return false;
	}
	return prod == 1 && sum == 0;
}

ll solve() {
	ll sum = 0;
	int m;
    cin>>m;

    vector<pll> a(m);
	for (int i = 0; i < m; i++) {
		cin>>a[i].first>>a[i].second;
		sum += a[i].first * a[i].second;
	}
	for (ll x = 1; x < sum && x < 30303; x++) {
		if (trySolve(sum - x, x,a)) return sum - x;
	}
	return 0;
}


int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    rep(0,test,T){
        cout<<"Case #"<<test+1<<": "<<solve()<<endl;
    }
    
    return 0;
}


