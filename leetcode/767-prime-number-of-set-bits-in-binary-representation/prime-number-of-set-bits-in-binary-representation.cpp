class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false; // 0, 1, and negatives are not prime
        if (n <= 3) return true;  // 2 and 3 are prime

        // Eliminate even numbers and multiples of 3 quickly
        if (n % 2 == 0 || n % 3 == 0) return false;

        // Check divisors from 5 to sqrt(n), skipping even numbers
        for (int i = 5; i <= sqrt(n); i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; ++i) {
            if(isPrime(__builtin_popcount(i))) {
                cout << i << endl;
                cnt++;
            }
        }
        return cnt;
    }
};