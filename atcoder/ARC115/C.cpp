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
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    vi a(n+1,0);
    a[1]=1;
    
    repe(2,r,n){
        for(int p=2;p*p<=r;p++){
            if(r%p==0){
                a[r]=a[r/p]+1;
                break;
            }
        }
        if(a[r]==0)a[r]=2;
    }
    for(int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
    return 0;
}

/*
题目要求所有数是整数
1是所有数的因子, 因此1的数应该唯一
所有质数因为没有1以外的因子, 取和 A[1] 不同的最小值

*/