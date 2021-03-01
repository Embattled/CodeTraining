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
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define mp make_pair
#define fr first
#define sc second


int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // x run cost    big number
        // y stop time   max 500
        // q awake       max 500
        // p sleep       big number

        ll x,y,p,q;
        ll res=0;
        cin>>x>>y>>p>>q;

        ll frak=p;
        ll frav=x;
        
        // arrav b and stop
        // (frav + n*(2X+2Y) , frav+y + n*(2X+2Y)

        // awake
        // (p + n*(P+Q)  , p+q + n* (P+Q)

        ll ro_r=2*x+y;
        ll ro_ta=p+q;

        if(frav+y<=frak||frak+q<=frav){

            ll dif=frav-frak;

            

            

        }

    }
    

    return 0;
}
