#include <stack>
#include <queue>
#include <set>
#include <array>
#include <vector>
#include <deque>
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
typedef pair<ull,ull> pull;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()

int findf(vi &father,int i){
    if(father[father[i]]!=father[i]){
        father[i]=findf(father,father[i]);
    }
    return father[i];
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    unordered_set<int> s1,s2;
    vi father(200001,0);
    vi a(n,0);
    for(auto &i:a){
        cin>>i;
        s1.insert(i);
        father[i]=i;
    }
    int l=0,r=n-1;
    while(l<r){
        father[findf(father,a[r])]=findf(father,a[l]);
        l++;
        r--;
    }
    for(auto &i:a){
        s2.insert(findf(father,i));
    }   

    cout<<s1.size()-s2.size()<<endl;

    return 0;
}
