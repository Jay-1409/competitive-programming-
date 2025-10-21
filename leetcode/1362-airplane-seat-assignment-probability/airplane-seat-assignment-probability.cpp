class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return (n >= 2 ? 0.5 : 1);
    }
};
/**
NOTES
What states can i cache? 

- case 1 -> first person choose the correct seat -> OVERALL OUTPUT POSITIVE 
- case 2 -> first pserson chosse the nth person seat -> OVERALL OUTPUT NEGATIVE
- case 3 -> first person choose neither the first seat nor the nth persons seat
            in this case he choose some seat between 2 to n-1
            _ _ _ _ _ 
            say that after some arrivals and some random seat chooses 
            there comes some perso whose seat is occupied 
            the probabilty that he chooses the seat n and seat 1 is equally likely 
The final probability would then become 
    Using total probability theorm 
    pr(n) = summation(1, n) [pr(first person choose k) * pr(nth person choose seat n | first person choose k)]
          = 0.5
**/