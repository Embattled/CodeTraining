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

    cin>>n>>m;

    vi arr(n);
    vi buf(n,0);
    set<int> s;
    for (int i = 0; i <= n; i++)
    {
        s.insert(i);
    }
    int res=n;

    int i=0;
    for (; i < m; i++)
    {
        cin>>a;
        arr[i]=a;

        buf[a]++;
        s.erase(a);
    }
    res=min(res,*s.begin());
    for ( ; i < n; i++)
    {
        cin>>a;
        arr[i]=a;

        s.erase(a);
        buf[a]++;

        buf[arr[i-m]]--;
        if(buf[arr[i-m]]==0){
            s.insert(arr[i-m]);
        }
        res=min(res,*s.begin());
    }
    cout<<res<<endl;
    return 0;
}
