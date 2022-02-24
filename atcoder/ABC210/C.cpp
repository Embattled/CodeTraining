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

int main(int argc, char const *argv[])
{
    int n,k;

    cin>>n>>k;

    vi c(n);
    unordered_map<int,int> memo;
    unordered_set<int> s;

    int i=0;
    for(;i<k;i++){
        cin>>c[i];

        memo[c[i]]++;
        s.insert(c[i]);
    }
    int res=s.size();

    for(;i<n;i++){
        cin>>c[i];

        memo[c[i]]++;
        s.insert(c[i]);

        memo[c[i-k]]--;
        if(memo[c[i-k]]==0){
            s.erase(c[i-k]);
        }
        res=max(res,(int)s.size());
    }

    cout<<res<<endl;
    
    return 0;
}
