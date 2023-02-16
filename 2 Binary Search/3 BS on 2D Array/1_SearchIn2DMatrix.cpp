#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size()-1;
        while(r < matrix.size() && c >= 0)
        {
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] < target)
                r++;
            else c--;
        }
        return false;
    }
};