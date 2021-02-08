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
    double x,y,r;

    cin >> x >> y >> r;

    long long res=0;

    long long row=ceil(x-r);
    long long rowe=floor(x+r);
    long long col=floor(y);
    long long cole=ceil(y);

    while (row!=rowe)
    {
        

        row++;
    }

    cout<<res<<endl;

    return 0;
}


