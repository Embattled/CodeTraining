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

int ten[]={1,10,100,1000,10000,100000};
int cs(string s){
    int n[10]={0};
    for (int i = 0; i < 5; i++)
    {
        n[s[i]-'0']++;
    }

    int score=0;
    for (int i = 1; i < 10; i++)
    {
        score+=i*ten[n[i]];
    }
    
    return score;
}

int main()
{
    int k;
    string s, t;
    cin >> k >> s >> t;

    int sumcard=k*9-8;
    int sumcard2=sumcard-1;

    vector<int> card(10,k);
    for (int i = 0; i < 4; i++)
    {
        card[s[i]-'0']--;
        card[t[i]-'0']--;
    }
    
    double res=0;

    for (int taka = 1; taka < 10; taka++)
    {
        string st=s;
        st[4]=taka+'0';

        double p1=card[taka]/(double)sumcard;
        // cout<<"Taka:"<<st<<" score:"<<cs(st)<<" p:"<<p1<<endl;

        vector<int> card2(card);
        card2[taka]--;

        for (int aoki = 1; aoki < 10; aoki++)
        {
            string sa=t;
            sa[4]=aoki+'0';
            // cout<<"Aoki:"<<sa<<" score:"<<cs(sa)<<endl;

            if(cs(st)>cs(sa)){
                double p=p1*(card2[aoki]/(double)sumcard2);
                res+=p;
            }
        }
    }
    cout<<setprecision(10)<<res<<endl;
    return 0;
}
