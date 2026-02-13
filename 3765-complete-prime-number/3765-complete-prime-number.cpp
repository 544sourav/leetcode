class Solution {
public:
    bool checkPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    bool completePrime(int num) {
        if (!checkPrime(num)) return false;

        int temp = num;
        while (temp > 0) {
            if (!checkPrime(temp)) return false;
            temp /= 10;
        }

        
        int divisor = 1;
        while (divisor <= num) divisor *= 10;
        divisor /= 10;

        temp = num;
        while (divisor > 0) {
            if (!checkPrime(temp)) return false;
            temp %= divisor;
            divisor /= 10;
        }

        return true;
    }
};
