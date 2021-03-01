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
    ll n;
    cin >> n;

    unordered_set<ll> can;

    for(ll base=2;base*base<=n;base++){
        
        if(can.find(base)!=can.end()){
            continue;
        }
        ll now=base*base;
        while (now<=n)
        {
            can.insert(now);
            // cout<<"insert:"<<now<<endl;
            now*=base;
        }
    }
    cout<<n-can.size()<<endl;


    return 0;
}
