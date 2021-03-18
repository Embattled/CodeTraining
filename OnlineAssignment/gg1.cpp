#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int x;
	cin >> x;										// Reading input from STDIN
	int ans,n,m;
	int mindif=INT_MAX;
	cin>>n;

	// input flavors and no toppings
	vector<int> flavors(n);
	for(int i=0;i<n;i++){
		string name;
		cin>>name>>flavors[i];
		int dif=abs(flavors[i]-x);
		if(dif<=mindif){
			if(dif==mindif){
				ans=min(ans,flavors[i]);
			}
			else{
				ans=flavors[i];
				mindif=dif;
			}
		}
	}
	// one topping
	cin>>m;
	vector<int> tops(m);
	for(int i=0,j=1;i<m;i++){
		string name;
		cin>>name>>tops[i];
		
		for(int j=0;j<n;j++){
			int p=flavors[j]+tops[i];
			int dif=abs(p-x);
			if(dif<=mindif){
				if(dif==mindif){
					ans=min(ans,p);
				}
				else{
					mindif=dif;
					ans=p;
				}
			}
		}
	}

	// two toppings
	for(int i=0;i<m;i++){
		for(int k=0;k<m;k++){
			if(i==k)continue;
			for(int j=0;j<n;j++){
				int p=flavors[j]+tops[i]+tops[k];
				int dif=abs(p-x);
				if(dif<=mindif){
					if(dif==mindif){
						ans=min(ans,p);
					}
					else{
						mindif=dif;
						ans=p;
					}
				}
			}
		}
	}


	cout<<ans<<endl;
}
