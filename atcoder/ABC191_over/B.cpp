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
    int n,x;
    cin>>n>>x;

    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(a!=x){
            d.push_back(a);
        }
    }
    for (int i = 0 ; i < d.size(); i++)
    {
        cout<<d[i];
        if(i!=d.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}
