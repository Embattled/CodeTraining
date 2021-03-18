
ちょっと複雑な配列組み合わせ問題です
```cpp

// Input number of goods
ll n;
cin>>n;

// Use map to sort points of goods and count number of goods with same point.
// Mapを使って、同時に商品の点数を配列すると同じ点数の商品の数を統計する
map<int,int> cn;

// Composeは商品の点数が重複しない一つ点数配列は
// 全ての商品の順列数です
ll compose=1;
repe(1,i,n){
    int c;
    cin>>c;
    // 統計
    cn[c]++;
    // 更新
    compose=(compose*cn[c])%mod;
}
// これで、ある条件を満たす点数配列に対して、
// （同じ点数がある商品を考えて）全ての商品の順列はcompose個

// ここから条件を満たす点数配列の数を求めます
// 点数の種類の数
ll type=cn.size();

// 配列された点数arrayの
// 最後から1個点数を考えて、配列の数は1
ll order=1;

// 最後から2個点数を考えから、全ての点数を考えまで
auto index=++cn.rbegin();
while(index!=cn.rend()){
    // 新しい配列の数は
    // order[i]= (count_of_point[i]+1) * order[i-1]
    order=(order*(index->second+1)%mod);
    index++;
}

cout<<(order*compose)%mod<<endl;
```

