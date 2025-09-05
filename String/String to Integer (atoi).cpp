class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        // skip white space
        int i = 0;
        while(i < n && s[i] == ' ') ++i;

        // determine sign
        int sign = 1;
        if(i < n && s[i] == '-') {
            sign = -1;
            ++i;
        }
        else if(i < n && s[i] == '+') ++i;

        // make integer
        int num = 0;    // to avoid overflow we can also take long long
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            if((num > INT_MAX / 10) || ((num == INT_MAX / 10) && ((sign == 1 && (s[i] - '0') >= 7) || 
                    (sign == -1 && (s[i] - '0') >= 8)))) 
                return sign == 1 ? INT_MAX : INT_MIN; 
            
            num = (num * 10) + (s[i] - '0');
            ++i;
        }

        return sign * num;
    }
};