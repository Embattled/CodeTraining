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
    int n,m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1,vector<int>(n+1,1e6));
    vector<> r(n+1);
    for (int i = 0; i < n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        dist[a][b]=min(dist[a][b],c);
    }
    

    return 0;
}


/* 

 Time Limit: 3 sec / Memory Limit: 1024 MB

Score : 500

points
Problem Statement

In the Republic of AtCoder, there are N
towns numbered 1 through N and M roads numbered 1 through M.
Road i is a one-way road from Town Ai to Town Bi, and it takes Ci minutes to go through. It is possible that Ai=Bi

, and there may be multiple roads connecting the same pair of towns.
Takahashi is thinking about taking a walk in the country. We will call a walk valid when it goes through one or more roads and returns to the town it starts at.
For each town, determine whether there is a valid walk that starts at that town. Additionally, if the answer is yes, find the minimum time such a walk requires.
Constraints

    1≤N≤2000

1≤M≤2000
1≤Ai≤N
1≤Bi≤N
1≤Ci≤105
All values in input are integers. */