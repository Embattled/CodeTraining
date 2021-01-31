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
    int n,s,d;
    cin>>n>>s>>d;

    int *x=new int[n];
    int *y=new int[n];

    int ok=false;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];

        if(x[i]<s&&y[i]>d){
            ok=true;
        }
    }
    if (ok)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    



    return 0;
}
