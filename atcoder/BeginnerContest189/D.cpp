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
/* 
y0=x0;
for i≥1, yi=yi−1∧xi if Si is AND, and yi=yi−1∨xi if Si is OR.
*/
int main()
{
    int N;
    string S[61];

    cin>>N;
	S[0]="OR";
	for(int i=1;i<=N;i++)cin>>S[i];
	long ans=0;

	for(int i=0;i<=N;i++)if(S[i]=="OR")
	{
        // AND 的时候必须都是 True
        // OR 的时候 假设 A or B: B是单变量 A是之前的组合
        // 当前 ans 即是  B 为 false, A 为 True 的组合总数
        // 1<<i 是 B 为 True , A 为任意的 组合总数 
		ans+=1LL<<i;
	}
	cout<<ans<<endl;
    return 0;
}
