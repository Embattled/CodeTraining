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
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
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

const double pi = std::acos(-1);

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    double x0, y0, x2n, y2n;
    cin >> x0 >> y0 >> x2n >> y2n;

    double midx=(x0+x2n)/2;
    double midy=(y0+y2n)/2;

    double edge=hypot((x0-x2n),(y0-y2n))/2;
    double ang=2*pi/n;

    double oldang=atan2((y0-midy),(x0-midx));
    double newang=oldang+ang;

    cout<<std::fixed<<setprecision(10)<<midx+edge*cos(newang)<<" "<<midy+edge*sin(newang)<<endl;






    return 0;
}
