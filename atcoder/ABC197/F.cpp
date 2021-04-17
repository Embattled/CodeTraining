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
#include <numeric>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define mp make_pair
#define fr first
#define sc second

#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#define rep(s, i, n) for (int(i) = (s); (i) < (n); (i)++)
#define repe(s, i, n) for (int(i) = (s); (i) <= (n); (i)++)
#define rrep(s, i, n) for (int(i) = (s); (i) > (n); (i)--)
#define rrepe(s, i, n) for (int(i) = (s); (i) >= (n); (i)--)
#define allof(a) (a).begin(), (a).end()

int main(int argc, char const *argv[])
{
    int n,m;

    cin>>n>>m;

    
    return 0;
}


using namespace std;
int N,M;
int dist[1010][1010];
vector<int>G[1010][26];
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int a,b;
		char c;cin>>a>>b>>c;
		a--,b--;
		G[a][c-'a'].push_back(b);
		G[b][c-'a'].push_back(a);
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dist[i][j]=1e9;
	dist[0][N-1]=0;
	queue<pair<int,int> >P;
	P.push(make_pair(0,N-1));
	while(!P.empty())
	{
		int u=P.front().first,v=P.front().second;
		P.pop();
		for(int k=0;k<26;k++)
		{
			for(int i:G[u][k])for(int j:G[v][k])
			{
				if(dist[i][j]>dist[u][v]+1)
				{
					dist[i][j]=dist[u][v]+1;
					P.push(make_pair(i,j));
				}
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<N;i++)
	{
		int t=dist[i][i]*2;
		if(ans>t)ans=t;
		for(int k=0;k<26;k++)for(int j:G[i][k])
		{
			int t=dist[i][j]*2+1;
			if(ans>t)ans=t;
		}
	}
	cout<<(ans==(int)1e9?-1:ans)<<endl;
}