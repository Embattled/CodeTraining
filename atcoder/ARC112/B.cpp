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
    ll  B,C;
    cin >> B >> C;

    ll res=0;
    map<ll,int> range;
    
    // sub -1
    // range[B]-=1;
    range[B-(C/2)]+=1;

    // add 1
    // range[B]+=1;
    range[B+((C-2)/2)]-=1;

    // sub
    // range[-B]+=2;
    range[(-B)-((C-1)/2)]+=1;
    range[-(B-((C-1)/2))]-=1;

    int  mark=0;
    ll start;
    for(auto p:range){
        // cout<<p.fr<<"  "<<p.sc<<endl;
        if(p.sc==0&&mark==0){
            res+=1;
        }
        else{
            if(p.sc==0){
                continue;
            }
            else if(mark==0){
                start=p.fr;
            }
            
            mark+=p.sc;
            if(mark==0){
                res+=p.fr-start+1;
            }

        }
    }
    cout <<res<<endl;



    return 0;
}
