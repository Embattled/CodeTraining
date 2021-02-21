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
    int a,b,c;
    cin >> a>>b>>c;
    int sa=a%10;
    if(sa==0){
        cout<<0<<endl;
    }
    else if (sa==1){
        cout<<1<<endl;
    }
    else if (sa==5){
        cout<<5<<endl;
    }
    else if(sa==6){
        cout<<6<<endl;
    }
    else if(sa==4){
        if(b==1){
            cout<<4<<endl;
        }
        else{
            cout<<6<<endl;
        }
    }
    else{

        vector<vector<int>> nocbuf(10);

        for(int i=2;i<=9;i++){
            nocbuf[i].push_back(0);
            nocbuf[i].push_back(i);
            int now=(i*i)%10;

            while((i*now)%10!=i){
                nocbuf[i].push_back(now);
                now=(i*now)%10;
            }
            nocbuf[i][0]=now;
            cout<<i<<"'s list:";
            for(auto a:nocbuf[i]){
                cout<<a<<" ";
            }
            cout<<endl;
        }

        int noc=nocbuf[sa].size(); 
        int b=b%noc;
        if(b==0){
            cout<<nocbuf[sa][0]<<endl;
            return 0;
        }
        else if(b==1){
            cout<<nocbuf[sa][1]<<endl;
            return 0;
        }
        else{
            int now=b;
            int t=1;
            while(now%noc){
                t++;
                now*=b;
            }
            c=c%t;

            now=b;
            while(--t){
                now*=b;
            }
            b=now%noc;

            cout<<nocbuf[sa][b]<<endl;


        }
    }
    // int noc=nocbuf[sa].size();

    // int now=b;
    // int t=1;
    // while(now*b%noc){
    //     t++;
    // }




    // cout<<sa<<endl;
    return 0;
}
