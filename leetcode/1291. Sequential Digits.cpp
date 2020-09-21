/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:

Input: low = 100, high = 300
Output: [123,234]

Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:

    10 <= low <= high <= 10^9

*/

class Solution
{
public:
    std::vector<int> sequentialDigits(int low, int high)
    {
        std::vector<int> result;
        // 得到区间数字宽度
        int widthL = floor(log10(low));
        int widthR = floor(log10(high));

        // 针对区间中的不同位数
        for (int i = widthL; i <= widthR; i++)
        {
            int number = 1;
            int addNumber = 1;
            // 计算起始数字 和被加数字
            // 例：在 i=2 的时候，number=123 addNumber=111
            for (int loop = 1; loop <= i; loop++)
            {
                number = number * 10 + loop + 1;
                addNumber = addNumber * 10 + 1;
            }

            // 在最后一位数字达到9之前 每次给该数字加`11..1` 循环次数为 9-i
            for (int loop = 0; loop < 9 - i; loop++)
            {
                // 判定是否在区间内即可，未优化的写法
                if (number >= low && number <= high)
                    result.push_back(number);
                number += addNumber;
            }
        }
        return result;
    }
};