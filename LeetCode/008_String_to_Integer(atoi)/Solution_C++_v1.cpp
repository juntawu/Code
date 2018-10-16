// Accepted

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int pt = 0;

        // continuous spaces
        while(str[pt] == ' ')
            pt++;

        // sign
        int signPosition = -1;
        if(str[pt] == '-' || str[pt] == '+'){
            signPosition = pt;
            pt++;
        }

        // valid number
        long long int result = 0;
        bool NoValidNum = true;
        while(pt < len && str[pt] <= '9' && str[pt] >= '0'){
            if(NoValidNum)
                NoValidNum = false;
            result = result * 10 + (str[pt] - '0');
            // out of range
            if(signPosition >= 0 && str[signPosition] == '-' && result > pow(2, 31)  )
                return -pow(2, 31);
            if( (signPosition < 0 || (signPosition >= 0 && str[signPosition] == '+') ) && result > pow(2, 31) - 1)
                return pow(2,31)-1;

            pt++;
        }

        if(NoValidNum)
            return 0;
        else{
            if(signPosition >= 0 && str[signPosition] == '-')
                result = -result;

            return int(result);
        }
    }
};
