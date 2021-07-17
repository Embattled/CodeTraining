## F

* 半数学题
* 用到的定理有:
  * Burnside 快速算得独立的面数
  * 费马定理,  有 (a/b)%c = (a*b^(c-2))%c
  * 计算N个数相加等于S, 总的排列个数为 $C_N^S+N$


## C

需要留意当距离小于一步长的时候, 需要的步数是2 而不是1 

## D

* 给了5秒时间, 因此暴力破解可行
* 可以用深度搜索来模仿人类的搜索, 但是需要注意多种边界条件
  * 注意三个字符串的长度关系, 第三个字符串一定要最长
  * 注意结果中, 三个字符串的第一个字符代表的数字不能为0
  * 注意在搜索完成后, 要判断 carry 也为0, 才是真的符合条件


## E

* 注意是树, 因此没有环
  * 可以用BFS, 但是会爆内存
  * 用带回溯的DFS来减小内存开支, 可以通过
