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

class bit
{
private:
	int *data;
	int n;
public:
	bit(int n){
		data=new int[n+1]{0};
		this->n=n;
	}
	~bit(){
		delete[] data;
	}

	int lowbit(int x){
		return x&(-x);
	}

	void update(int index,int up){
		while(index<=n){
			data[index]+=up;
			index+=lowbit(index);
		}
	}
	int sum(int index){
		int res=0;
		while(index>0){
			res+=data[index];
			index-=lowbit(index);
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	bit mbit(n);
	vector<int> list(n);

	// 这里 ret 可能会越界 int 所以要用 long long 
	long long ret=0;
	for (int i = 0; i < n; i++)
	{
		cin>>list[i];
		list[i]++;
		
		ret+=i-mbit.sum(list[i]);
		mbit.update(list[i],1);
	}

	for (int i = 0; i < n; i++)
	{
		cout<<ret<<endl;
		// ret+=(n-1)-2*(list[i]-1)
		ret+=n-2*list[i]+1;
	}
	

	return 0;
}

/* 

 Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 600

points
Problem Statement

Given is a sequence A=[a0,a1,a2,…,aN−1]
that is a permutation of 0,1,2,…,N−1.
For each k=0,1,2,…,N−1, find the inversion number of the sequence B=[b0,b1,b2,…,bN−1] defined as bi=ai+kmodN

.
What is inversion number?
The inversion number of a sequence is the number of pairs of indices such that and .
Constraints

    All values in input are integers.
    2≤N≤3×105

a0,a1,a2,…,aN−1
is a permutation of 0,1,2,…,N−1

Input

Input is given from Standard Input in the following format:

N
a0 a1 a2 ⋯ aN−1


Output

Print N
lines.
The (i+1)-th line should contain the answer for the case k=i.
 */
