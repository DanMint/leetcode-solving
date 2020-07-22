class Solution {
public:
    int reverse(int x) {
        long long reversedNumber = 0;
 
    while (x != 0) {
        long long remainder = x % 10;
        reversedNumber = 10 * reversedNumber + remainder;
        x = x / 10;
    }
 
    if (reversedNumber < INT_MIN || reversedNumber > INT_MAX)
        return 0;
 
    return (int)reversedNumber;
    }
};

