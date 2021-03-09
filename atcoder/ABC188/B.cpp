#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

// int main(int argc, char const *argv[])
int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum+=a[i]*b[i];
    }

    if(sum==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
