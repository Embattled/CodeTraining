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
    int t=0;
    cin>>t;

    for (int i = 0; i < t; i++)
    {
        ll L,R;
        cin>> L >> R;
        if(L*2>R){
            cout<<0<<endl;
            continue;
        }
        ll res=0;

        ll n=(R-2*L)+1;
        ll startT=1;
        ll finT=(R-L)-L+1;

        res+= (startT+finT)*n/2;

        // for(ll r=2*L;r<=R;r++){
        //     res+=(r-L)-L+1;
        // }
        cout<<res<<endl;
    }

    return 0;
}
