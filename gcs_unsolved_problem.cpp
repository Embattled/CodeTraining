#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct node{
    int father;
    vector<int>* child;
};

vector<int> solve (int N, vector<int> values, vector<vector<int> > edges) {
   // Write your code here
   vector<int> result;

    node nodes[N];
    nodes[0].father=-1;

    queue<int> check;
    check.push(1);

   while(!check.empty()){
       int searchNode=check.front();
       check.pop();
        nodes[searchNode-1].child=new vector<int>;

       for(auto i=edge.begin();i!=edge.end();)
       {
           if((*i)[0]==searchNode){
               nodes[searchNode-1].child.push_back((*i)[1]);
               nodes[(*i)[1]].father=searchNode;
               i=edges.erase(i);
           }
           else if((*i)[1]==searchNode){
               nodes[searchNode-1].child.push_back((*i)[0]);
               nodes[(*i)[0]].father=searchNode;
               i=edges.erase(i);
           }
           else{
               i=i++;
           }
       }
       for(auto i:nodes[searchNode-1].child){
           check.push(i);
       }
   }
   
   for(int i=0;i<N;i++){
       int value=values[i];

       int index=i;

       while(index!=-1){
           index=nodes[index].father-1;
           if(values[index])
    
       }
   }

   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> values(N);
        for(int i_values = 0; i_values < N; i_values++)
        {
        	cin >> values[i_values];
        }
        vector<vector<int> > edges(N-1, vector<int>(2));
        for (int i_edges = 0; i_edges < N-1; i_edges++)
        {
        	for(int j_edges = 0; j_edges < 2; j_edges++)
        	{
        		cin >> edges[i_edges][j_edges];
        	}
        }

        vector<int> out_;
        out_ = solve(N, values, edges);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}


2
8
16 17 12 7 20 18 7 8 
6 8
3 8
8 1
2 7
2 3
7 5
2 4
6
5 19 12 10 9 16 
4 3
5 3
6 2
6 1
4 6

-1 3 -1 2 7 -1 2 -1 
-1 6 1 -1 4 1 

2
9
10 14 5 10 8 19 5 9 10
2 1
4 2
7 5
5 8
3 8
2 6
9 3
8 2
6
15 2 4 2 12 19
1 3
3 2
1 5
5 6
4 1

-1 -1 8 -1 8 2 5 2 8 
-1 1 1 1 -1 5 

3
5
16 3 11 3 6
5 1
1 4
3 5
4 2
8
20 13 11 10 7 15 5 17
6 2
8 3
3 1
5 4
2 3
7 4
1 5
3
15 3 16
2 1
1 3

-1 1 5 1 -1 
-1 3 1 5 1 2 5 3 
-1 -1 1 

3
5
16 10 6 9 9
2 4
2 5
3 1
3 4
1
16
9
6 19 18 20 19 18 7 17 10
8 2
9 1
5 7
6 9
4 8
3 5
4 9
9 7

-1 4 -1 1 2 
-1 
-1 8 5 -1 7 -1 9 4 -1 
