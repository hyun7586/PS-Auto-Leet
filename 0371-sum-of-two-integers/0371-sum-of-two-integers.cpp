class Solution {
public:
    int getSum(int a, int b) {
        int base = a^b;
        int carry = (a&b)<<1;

        while(carry!=0){
            a=base;
            b=carry;

            base=a^b;
            carry=(a&b)<<1;
        }

        return base;
    }
};