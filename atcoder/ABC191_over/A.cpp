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
    int v,t,s,d;
    cin >> v >> t >> s>>d;

    if (d<v*t||d>v*s)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    

    return 0;
}
