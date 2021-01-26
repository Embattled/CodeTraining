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
    int n;
    cin >> n;
    stack<int> st;

    int v=1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (s=="AND")
        {
           v++; 
        }
        else
        {
            st.push(v);
            v=1;
        }
    }
    st.push(v);

    unsigned long long trueOld=0;
    int length=0;
    while (!st.empty())
    {
        int v=st.top();
        st.pop();
        // cout<<"V:"<<v<<endl;

        unsigned long long allnew=1<<(v);
        unsigned long long allold=1<<(length);

        trueOld=allold+(allnew-1)*trueOld;
        length+=v;
    }
    cout<<trueOld<<endl;
    return 0;
}
