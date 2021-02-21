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
    string s;
    cin>>s;

    int n=s.length();
    bool yes=true;

    for (int i = 0; i < n; i+=2)
    {
        if(isupper(s[i])){
            yes=false;
            break;
        }
    }
    for (int i = 1; i < n; i+=2)
    {
        if(islower(s[i])){
            yes=false;
            break;
        }
    }
    
    

    if(yes)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;

}
