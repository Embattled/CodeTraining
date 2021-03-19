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
    
    string name[2]={"Takahashi","Aoki"};

    string s;
    string x;
    cin>>s>>x;

    vector<vector<int>> dp(n+1,vector<int>(7,0));
    dp[n][0]=1;

    rrepe(n-1,i,0){
        int num=s[i]-'0';

        if(x[i]=='T'){
            rep(0,j,7){
                if(dp[i+1][(j*10)%7]==1||dp[i+1][(j*10+num)%7]==1){
                    dp[i][j]=1;
                }
            }
        }
        else{
            rep(0,j,7){
                if(dp[i+1][(j*10)%7]==1&&dp[i+1][(j*10+num)%7]==1){
                    dp[i][j]=1;
                }
            }
        }
    }
    cout<<name[1-dp[0][0]]<<endl;
    return 0;
}
