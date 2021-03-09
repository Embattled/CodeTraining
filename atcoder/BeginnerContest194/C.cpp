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

    cin>>n;
    ull res=0;

    vi old(401,0);
    vector<vector<ll>> data(401,vector<ll>(401));
    for (int i = -200; i <=200; i++)
    {
        for (int j = -200; j <= 200; j++)
        {
            ll val=(i-j)*(i-j);
            data[i+200][j+200]=val;
            // data[j+200][i+200]=val;
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        cin>>a;
        for (int j = -200; j <=200; j++)
        {
            res+=old[j+200]*data[a+200][j+200];
        }
        old[a+200]++;
    }
    cout<<res<<endl;
    return 0;
}
