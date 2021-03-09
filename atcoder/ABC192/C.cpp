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

string s;
string s1,s2;

ll g1(){
    s1=s;
    sort(s1.begin(),s1.end(),greater<int>());
    // cout<<s1<<endl;
    return stoll(s1);
}
ll g2(){
    s2=s;
    sort(s2.begin(),s2.end(),less<int>());
    // cout<<s2<<endl;
    return stoll(s2);
}

int main()
{
    ll N,K;
    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        s=to_string(N);
        // cout<<s<<endl;
        N=g1()-g2();
        
    }
    cout<< N<<endl;
    

    return 0;
}
