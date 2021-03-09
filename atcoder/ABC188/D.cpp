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

#include <algorithm>
#include <cmath>

#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
int main()
{
    long long n;
    long long C;
    cin >> n >> C;
    map<long long,long long> data;
    long long nowSum=0;
    long long nowCost=0;
    for(long long i=0;i<n;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        data[a]+=c;
        data[b+1]-=c;
    }
    long long day=0;
    for(auto &d:data){
        long long diffDay=d.first-day;
        long long addV;
        if(nowSum>C){
            addV=diffDay*C;
        }
        else
        {
            addV=diffDay*nowSum;
        }
        nowCost+=addV;

        nowSum+=d.second;
        day=d.first;
    }
    cout<<nowCost<<endl;
    return 0;
}
