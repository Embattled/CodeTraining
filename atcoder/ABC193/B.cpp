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
    int n;
    cin >> n;

    int res=INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int a,p,x;
        cin>>a>>p>>x;

        if(a<x){
            res=min(res,p);
        }

    }
    if(res==INT_MAX){
        cout<<-1<<endl;
    }
    else
        cout<<res<<endl;
    

    return 0;
}
