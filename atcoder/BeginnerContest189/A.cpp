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
    string s;
    
    cin >> s;
    if(s[0]==s[1]&&s[0]==s[2]){
        cout<<"Won"<<endl;
    }
    else
    {
        cout<<"Lost"<<endl;
    }
    

    return 0;
}
