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

#include <iostream>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;

    char data[10][10];

    int si,sj;
    bool fs=true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin>>data[i][j];
            if(fs&&data[i][j]=='#'){
                si=i;
                sj=j;
                fs=false;
            }
        }
    }
    
    int res=0;
    int m[5]{0,1,0,-1,0};

    int i=si,j=sj;
    int dire=0;

    while(1){
        int wdire=(dire+3)%4;

        // cout<<"Now pos"<<i<<" "<<j<<" dire:"<<dire<<endl;
        while((data[i+m[dire]][j+m[dire+1]]=='#')&&data[i+m[wdire]][j+m[wdire+1]]=='.'){
            i+=m[dire];
            j+=m[dire+1];
            // cout<<"Now pos"<<i<<" "<<j<<" dire:"<<dire<<endl;
        }
        res++;
        if(data[i+m[wdire]][j+m[wdire+1]]=='#'){
            dire=wdire;
            i+=m[dire];
            j+=m[dire+1];
        }
        else{
            dire=(dire+1)%4;
        }
        if(i==si&&j==sj&&dire==0){
            break;
        }
    };
    cout<<res<<endl;
    
    

    return 0;
}
