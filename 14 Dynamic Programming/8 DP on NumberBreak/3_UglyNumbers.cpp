#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ugly-number-ii/description/?envType=study-plan&id=dynamic-programming-i

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int uglyNumbers[n];
        uglyNumbers[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        int nextUglyNumber = 1;

        for (int i = 1; i < n; i++)
        {
            nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;
            if (nextUglyNumber == nextMultipleOf2)
            {
                i2 += 1;
                nextMultipleOf2 = uglyNumbers[i2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3)
            {
                i3 += 1;
                nextMultipleOf3 = uglyNumbers[i3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5)
            {
                i5 += 1;
                nextMultipleOf5 = uglyNumbers[i5] * 5;
            }
        }
        return nextUglyNumber;
    }
};