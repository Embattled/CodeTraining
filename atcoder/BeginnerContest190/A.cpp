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
    int a,b,c;
    
    cin >> a>>b>>c;
    string name[2]={"Takahashi","Aoki"};

    int win=0;
    if(c==0){
        if(a>b){
            win=0;
        }
        else
        {
            win=1;
        }
    }
    else
    {
        if(b>a){
            win=1;
        }
        else
        {
            win=0;
        }
        

    }
    cout<<name[win]<<endl;
    

    return 0;
}
