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
    int n;
    
    cin >> n;
    vector<int> data(n);

    int maxSum=0;
    int minO=INT_MAX;
    int start=0;
    for (int i = 0; i < n; i++)
    {
        cin>>data[i];
        int minO=INT_MAX;
        for (int j = i; j >=0; j--)
        {
            minO=min(minO,data[j]);
            maxSum=max(maxSum,(i-j+1)*minO);
            if((i+1)*minO<maxSum)break;
        }
        // cout<<maxSum<<endl;
    }
    cout<<maxSum<<endl;
    
    
    return 0;
}
