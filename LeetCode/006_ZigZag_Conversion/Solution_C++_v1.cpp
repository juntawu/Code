#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
		// output in one line
		if(1 == numRows)
			return s;
		
		// find the rule: split the string into several sub-strings according to the numRows
        int step = 2 * numRows - 2;  // length of sub-string
        int len = s.size();  // length of the whole string
        for(int i=0; i<numRows; i++){       
            int pt = 0;  // base index of the sub-string
            while(pt >=0 && pt <len){
                if(pt + i >= 0 && pt + i < len)
                    result += s[pt + i];  // first character of sub-string in (i+1)-th line
                if(i>0 && step-i > i && pt+(step-i) < len)
                    result += s[pt+(step-i)];  // second character of sub-string in (i+1)-th line
                pt += step;
            }
        }
		
		return result;
    }
};



int main(){
	Solution solver = Solution();
	string str = "PAYPALISHIRING";
	// string str = "A";
	cout << solver.convert(str, 14) << endl;
	
	return 0;
}