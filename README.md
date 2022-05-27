# CodeTraining
Save all code problem solution.

## Atcoder

Atcoder competitions source code.


## Leetcode

Interesting problem in leetcode. (Uncompileable)

## Google

Source code of Google's coding competitions.



# 经验总结


* 公式上可能有除法的地方尽量使用乘法代替
* 对于大的分情况, 可以直接从变量上分开讨论, 不用循环也可以
* 对于优化问题中不可能的情况, 直接用无限大的权值来标识


## 数学

* 进制的概念, k 进制标识一个数字n, 每一位数字ai, 相当于 $n= a_mk^m+...+a_2k^2+a_1k+a_0$
  * 对于某一个范围的数字, 最大值需要 m 位 k 进制的数字标识
  * 则, 共需要 `m*(k-1)` 个数字作为子单位, 执行 m 次加法得到