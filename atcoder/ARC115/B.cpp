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

/*
We can assume that the minimum value in A is 0, because if there is some pair A,B satisfying the condition such that the minimum value in A is m(>0), we can subtract m from all elements in A and add m to all elements in B

, and the pair still satisfies the condition.

If the minimum element in A
is 0, we can determine A as Ai=Ci,0−m, where m is the minimum value among Ci,0, and B as Bj=C0,j−A0

.

Lastly, we check if this pair A,B

actually satisfies all conditions, and the problem is solved.

*/
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int> > c(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> c[i][j];
    }


    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = c[i][0] - c[0][0];
 
    // b[i]=  Bi
    vector<int> b = c[0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(c[i][j] != a[i] + b[j]){
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    int amin = 2e9;
    for(int x : a) amin = min(amin, x);

    int bmin = 2e9;
    for(int x : b) bmin = min(bmin, x);

    
    if(amin + bmin < 0){
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        for(int x : a) cout << (x - amin) << ' ';
        cout << '\n';
        for(int x : b) cout << (x + amin) << ' ';
        cout << '\n';
    }
}