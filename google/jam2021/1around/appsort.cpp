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

int put0(string &s,int n){
    int res=0;
    while(s.length()<n){
        res++;
        s.push_back('0');
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    rep(0,test,T){
        int n;
        cin>>n;
        vector<string> data(n);
        rep(0,i,n){
            cin>>data[i];
        }
        string now=data[0];
        int res=0;
        rep(1,i,n){
            string &olds=data[i-1];
            string &news=data[i];
            int lenold=olds.length();
            int lennew=news.length();
            if(lennew>lenold)continue;
            else if(lennew==lenold){
                bool small=true;
                rep(0,j,lennew){
                    if(news[j]<olds[j]){
                        break;
                    }
                    else if(news[j]>olds[j]){
                        small=false;
                        break;
                    }
                }
                if(small){
                    res++;
                    news.push_back('0');
                }
                continue;
            }

            bool equal=true;
            bool small=true;

            for(int j=0;j<lennew;j++){
                if(news[j]<olds[j]){
                    equal=false;
                    break;
                }
                else if(news[j]>olds[j]){
                    equal=false;
                    small=false;
                    break;
                }       
            }
            if(!equal&&small)res+=put0(news,lenold+1);
            else if(!equal&&!small)res+=put0(news,lenold);
            else{
                int add1=1;
                string back="";
                for(int k=lenold-1;k>=lennew;k--){
                    char c=olds[k]+add1;
                    if(c>'9'){
                        c='0';
                    }
                    else{
                        add1=0;
                    }
                    back=c+back;
                }
                if(add1){
                    res+=put0(news,lenold+1);
                }
                else{
                    news+=back;
                    res+=back.length();
                }
            }
        }

        cout<<"Case #"<<test+1<<": "<<res<<endl;
    }
    
    return 0;
}
