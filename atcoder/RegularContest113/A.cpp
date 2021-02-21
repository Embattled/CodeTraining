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
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define mp make_pair
#define fr first
#define sc second


int main()
{
    ll res=0;
    int k;

    cin >> k;

    // i<= p1,p2
    for(int i=1;i*i<=k;i++){
        res+=k/(i*i);

        // cout<<"firsti:"<<i<<"  add:"<<k/(i*i)<<endl;

        // j <= d
        ll a=0;
        for(int j=i+1;i*j<=k;j++){

            int d=k/(i*j);
            // cout<<"i: "<<i<< " j: "<<j<<" d: "<<d<<endl;
            a+=d;
        }
        res+=2*a;
    }
    cout<<res<<endl;
    return 0;
}
