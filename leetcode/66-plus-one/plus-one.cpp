class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nextcarry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            digits[i] += nextcarry;
            nextcarry = max(digits[i] - 9, 0);
            if(digits[i] >= 10 && i > 0){
                digits[i] -= 10;
            }
        }           
        reverse(digits.begin(),digits.end());
        if(digits.back() >= 10){
            int val = digits.back() % 10;//0
            digits.back() /= 10;
            int val2 = digits.back() % 10;//1
            digits.back() = val;
            digits.push_back(val2);
            // reverse(digits.begin(),digits.end());
        }
            reverse(digits.begin(),digits.end());
        return digits;
    }
};