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
#include <iomanip>
using namespace std;

int N,M,K;
int A[11];
double da[2<<17],db[2<<17];
bool out[1<<17];
main()
{
	cin>>N>>M>>K;
	for(int i=0;i<K;i++)
	{
		cin>>A[i];
		out[A[i]]=true;
	}
	double sa=0,sb=0;

    // i >= 0
	for(int i=N;i--;)
	{
        // 是回到起点的方块 db=1
		if(out[i])db[i]=1;
		else
		{
            // da 是 sa/M +1
            // 从N点 到达该点的期望步数
            // da[N-1] = 1
			da[i]=sa/M+1;

            // db 是 sb/M
            // db[N-1] = 0
			db[i]=sb/M;
		}
        // sa加上 当前 da
		sa+=da[i];

        // sb加上 当前 db
		sb+=db[i];

        // 减去 当前最多到达的下一方块的 da
		sa-=da[i+M];

        // 减去 当前最多到达的下一方块的 db
		sb-=db[i+M];
	}



	double ans;
	if(K==0)ans=da[0];
	else if(db[0]<1-1e-8)
	{
		ans=da[0]/(1-db[0]);
	}
	else
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(16)<<ans<<endl;
}
