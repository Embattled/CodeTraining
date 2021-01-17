#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])

int n,x,y;
void vert(char &c)
{
    if (c == 'R')
        c = 'B';
    else if (c == 'B')
        c = 'R';
}
int cal(vector<char> a,vector<char> b,int start,int mustVert){
    if(mustVert==n-start){
        return y*mustVert;
    }

    if(a[start]==b[start]){
        return cal(a,b,start+1,mustVert);
    }
    

}
int main()
{
    cin >> n >> x >> y;

    vector<char> a(n);
    vector<char> b(n);
    int numra=0,numrb=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]=='R')
        {
            numra++;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i]=='R')
        {
            numrb++;
        }
    }
    int mustVertR=numra-numrb;
    int mincost=0;

    int start=0;
    while (a[start]==b[start])
    {
        start++;
    }
    mincost=cal(a,b,start,mustVertR);    
    return 0;
}
