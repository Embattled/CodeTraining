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


int main(int argc, char const *argv[])
{
    int x,y,a,b,n,m,k,j;

    cin>>a>>b;
    
    int res;
    if(a+b>=15&&b>=8)res=1;
    else if(a+b>=10&&b>=3)res=2;
    else if(a+b>=3)res=3;
    else res=4;

    cout<<res<<endl;

    return 0;
}
