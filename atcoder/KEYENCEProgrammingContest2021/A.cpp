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
int main()
{
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    long long maxA=0,maxB=0;
    long long sum=0;

    for (int i = 0; i < n; i++)
    {
        if(a[i]>maxA){
            maxA=a[i];
            maxB=b[i];
        }
        else if(b[i]>maxB){
            maxB=b[i];
        }
        sum=max(sum,maxA*maxB);
        c[i]=sum;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<c[i]<<endl;
    }

    return 0;
}
