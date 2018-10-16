//From: https://leetcode.com/problems/string-to-integer-atoi/discuss/177227/C++-solution-:-4-lines-of-code-using-stringstream-12ms-(Accepted)
//Simple implementation with stingstream(STL)

class Solution {
public:
      int myAtoi(string str) {
        stringstream input(str);
        
        int x =0;
        input>>x;        
        return x;
    }
};