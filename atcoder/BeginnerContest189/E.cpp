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
    long long n;
    cin >> n;
    vector<vector<pair<long long, long long>>> data(n);

    for (long long i = 0; i < n; i++)
    {
        pair<long long, long long> point;
        cin >> point.first >> point.second;
        data[i].push_back(point);
    }

    long long m;
    cin >> m;
    vector<pair<long long, long long>> ops(m);
    for (long long i = 0; i < m; i++)
    {
        cin >> ops[i].first;
        if (ops[i].first > 2)
        {
            cin >> ops[i].second;
        }
    }

    long long q;
    cin >> q;
    for (long long lo = 0; lo < q; lo++)
    {
        long long a, b;
        cin >> a >> b;

        if (data[b - 1].size() <= a)
        {
            auto point = data[b - 1].back();
            for (int i = data[b - 1].size(); i <= a; i++)
            {
                auto op = ops[i - 1];
                if (op.first == 1)
                {
                    long long x = point.second;
                    point.second = -point.first;
                    point.first = x;
                }
                else if (op.first == 2)
                {
                    long long x = point.first;
                    point.first = -point.second;
                    point.second = x;
                }
                else if (op.first == 3)
                {
                    point.first = 2 * op.second - point.first;
                }
                else
                {
                    point.second = 2 * op.second - point.second;
                }
                data[b - 1].push_back(point);
                // cout<<"Now size:"<<data[b - 1].size()<<endl;
            }
        }
        cout << data[b - 1][a].first << " " << data[b-1][a].second << endl;
    }
    return 0;
}


int N;
int X[2<<17],Y[2<<17];
int M,Q;
int t[2<<17],p[2<<17];
vector<pair<int,int> >G[2<<17];
long aX[2<<17],aY[2<<17];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>t[i];
		if(t[i]>=3)cin>>p[i];
	}
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int a,b;cin>>a>>b;
		G[a].push_back(make_pair(b-1,i));
	}
	long a=1,b=0,c=0,d=0,e=1,f=0;
	for(int i=0;i<=M;i++)
	{
		for(pair<int,int>p:G[i])
		{
			long tx=a*X[p.first]+b*Y[p.first]+c;
			long ty=d*X[p.first]+e*Y[p.first]+f;
			aX[p.second]=tx;
			aY[p.second]=ty;
		}
		if(i==M)break;
		if(t[i]==1)
		{
			long ta=a,tb=b,tc=c;
			a=d;b=e;c=f;
			d=-ta;e=-tb;f=-tc;
		}
		else if(t[i]==2)
		{
			long ta=a,tb=b,tc=c;
			a=-d;b=-e;c=-f;
			d=ta;e=tb;f=tc;
		}
		else if(t[i]==3)
		{
			a=-a;b=-b;c=2*p[i]-c;
		}
		else
		{
			d=-d;e=-e;f=2*p[i]-f;
		}
	}
	for(int i=0;i<Q;i++)cout<<aX[i]<<" "<<aY[i]<<endl;
}
