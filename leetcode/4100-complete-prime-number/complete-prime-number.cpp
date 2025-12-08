class Solution {
public:
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;
        if (n % 3 == 0) return n == 3;
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        if(!isPrime(num))
            return false;
        int digs = 0;
        int copy_num = num;
        while(copy_num > 0) {
            copy_num /= 10;
            digs++;
        }
        for(int i = 1; i < digs; ++i) {
            int mod_val = pow(10, digs - i);
            int prefix = num / mod_val;
            int suffix = num - (prefix * mod_val); 
            if(!isPrime(prefix) || !isPrime(suffix)){
                return false;
            }
        }
        return true;
    }
};