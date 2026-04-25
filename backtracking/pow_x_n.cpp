// https://leetcode.com/problems/powx-n/description/

class Solution {
    public:
        double myPow(double x, int n) {
            return myPowHelper(x, (long long)n);
        }
    
    private:
        double myPowHelper(double x, long long n) {
            if (n < 0) {
                return 1 / myPowHelper(x, -n);
            } else if (n == 0) {
                return 1;
            } else if (n % 2 == 0) {
                return myPowHelper(x * x, n / 2);
            } else {
                return x * myPowHelper(x * x, (n - 1) / 2);
            }
        }
    };